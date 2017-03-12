#include "display.h"

Display::Display(Spectrum48KMemory* memory)
    : m_memory(memory),
      m_inverted(false),
      m_frames(0)
{
    // TODO: error handling
    generateVertexBuffer();
    generateUVs();

    glGenVertexArrays(1, &m_vaoID);
    glBindVertexArray(m_vaoID);
    glGenBuffers(1, &m_vboID); // vertices
    glBindBuffer(GL_ARRAY_BUFFER, m_vboID);
    glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * m_vertexBuffer.size(), m_vertexBuffer.data(), GL_STATIC_DRAW);
    glGenBuffers(1, &m_uvID);   // UVs
    glBindBuffer(GL_ARRAY_BUFFER, m_uvID);
    glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * m_UVs.size(), m_UVs.data(), GL_STATIC_DRAW);

    glGenTextures(1, &m_textureID);
    glBindTexture(GL_TEXTURE_2D, m_textureID);
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST );
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, DISPLAY_WIDTH, DISPLAY_HEIGHT, 0, GL_BGR, GL_UNSIGNED_BYTE, m_pixels);

    GLuint vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
    GLuint fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
    std::string vertexShaderCode = readFileToString(VERTEX_SHADER_FILE);
    std::string fragmentShaderCode = readFileToString(FRAGMENT_SHADER_FILE);
    compileShader(vertexShaderCode, vertexShaderID);
    compileShader(fragmentShaderCode, fragmentShaderID);
    GLuint programID = linkShaderProgram(vertexShaderID, fragmentShaderID);
    glDetachShader(programID, vertexShaderID);
    glDetachShader(programID, fragmentShaderID);

    glDeleteShader(vertexShaderID);
    glDeleteShader(fragmentShaderID);

    m_samplerID = glGetUniformLocation(programID, "inTexture");

    m_programID = programID;
}

Display::~Display()
{
    glDeleteBuffers(1, &m_vboID);
	glDeleteBuffers(1, &m_uvID);
	glDeleteProgram(m_programID);
	glDeleteTextures(1, &m_samplerID);
	glDeleteVertexArrays(1, &m_vaoID);
}

void Display::draw(int windowWidth, int windowHeight)
{
    // TODO: error handling

    for (uint8_t y = 0; y < DISPLAY_HEIGHT; y++)
    {
        for (uint8_t x = 0; x < DISPLAY_WIDTH/8; x++)
        {
            uint16_t memY = 0x4000 | ((y >> 6) << 11);
            memY |= (y & 0x7) << 8;
            memY |= ((y >> 3) & 0x7) << 5;

            uint16_t memPos = memY |= x;
            for (uint8_t bit = 0; bit < 8; bit++)
            {
                // Find the corresponding color attributes
                // http://www.animatez.co.uk/computers/zx-spectrum/screen-memory-layout/
                int xReal = x * 8 + bit;
                uint16_t memCol = 0x5800 + ( (y / 8) * (DISPLAY_WIDTH / 8) + (xReal / 8) );
                uint8_t attributes = (*m_memory)[memCol];

                // Find the color (each is stored as 1 bit per channel in GRB format)
                bool col = ((*m_memory)[memPos] & (1 << (7 - bit)));
                col = (m_inverted && (col >> 7)) ? !col : col;
                uint8_t r = col ? (attributes & 0x2) >> 1 : (attributes & 0x10) >> 4;
                uint8_t g = col ? (attributes & 0x4) >> 2 : (attributes & 0x20) >> 5;
                uint8_t b = col ? (attributes & 0x1) : (attributes & 0x8) >> 3;

                // Adjust by brightness flag
                r *= (attributes & 0x40) ? 255 : 128;
                g *= (attributes & 0x40) ? 255 : 128;
                b *= (attributes & 0x40) ? 255 : 128;

                m_pixels[ (DISPLAY_WIDTH * y + (x*8+bit)) * 3 ] = b;
                m_pixels[ (DISPLAY_WIDTH * y + (x*8+bit)) * 3 + 1 ] = g;
                m_pixels[ (DISPLAY_WIDTH * y + (x*8+bit)) * 3 + 2 ] = r;

            }
        }
    }

    glDraw(windowWidth, windowHeight);

    m_frames++;
    if (m_frames > 15)
    {
        m_frames = 0;
        m_inverted = !m_inverted;
    }
}

void Display::glDraw(int width, int height)
{
    glUseProgram(m_programID);
    mat4 mvp = multiply(projectionOrtho((GLfloat)width, (GLfloat)height, -1.0f, 1.0f),
        identityMatrix());
    GLuint MatrixID = glGetUniformLocation(m_programID, "MVP");
    glUniformMatrix4fv(MatrixID, 1, GL_FALSE, mvp.data());
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, m_textureID);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, DISPLAY_WIDTH, DISPLAY_HEIGHT, 0, GL_BGR, GL_UNSIGNED_BYTE, m_pixels);
    glUniform1i(m_samplerID, 0);
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, m_vboID);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*) 0);
    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, m_uvID);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, (void*) 0);
    glDrawArrays(GL_TRIANGLES, 0, 6);
    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
}

void Display::generateVertexBuffer()
{
    m_vertexBuffer.push_back(-0.5f * DISPLAY_WIDTH);
    m_vertexBuffer.push_back(-0.5f * DISPLAY_HEIGHT);
    m_vertexBuffer.push_back(0.0f);

    m_vertexBuffer.push_back(0.5f * DISPLAY_WIDTH);
    m_vertexBuffer.push_back(-0.5f * DISPLAY_HEIGHT);
    m_vertexBuffer.push_back(0.0f);

    m_vertexBuffer.push_back(0.5f * DISPLAY_WIDTH);
    m_vertexBuffer.push_back(0.5f * DISPLAY_HEIGHT);
    m_vertexBuffer.push_back(0.0f);

    m_vertexBuffer.push_back(-0.5f * DISPLAY_WIDTH);
    m_vertexBuffer.push_back(-0.5f * DISPLAY_HEIGHT);
    m_vertexBuffer.push_back(0.0f);

    m_vertexBuffer.push_back(0.5f * DISPLAY_WIDTH);
    m_vertexBuffer.push_back(0.5f * DISPLAY_HEIGHT);
    m_vertexBuffer.push_back(0.0f);

    m_vertexBuffer.push_back(-0.5f * DISPLAY_WIDTH);
    m_vertexBuffer.push_back(0.5f * DISPLAY_HEIGHT);
    m_vertexBuffer.push_back(0.0f);
}

void Display::generateUVs()
{
    m_UVs.push_back(0.0f);
    m_UVs.push_back(1.0f);

    m_UVs.push_back(1.0f);
    m_UVs.push_back(1.0f);

    m_UVs.push_back(1.0f);
    m_UVs.push_back(0.0f);

    m_UVs.push_back(0.0f);
    m_UVs.push_back(1.0f);

    m_UVs.push_back(1.0f);
    m_UVs.push_back(0.0f);

    m_UVs.push_back(0.0f);
    m_UVs.push_back(0.0f);
}

bool Display::compileShader(std::string code, GLuint shaderID)
{
    GLint Result = GL_FALSE;
    int InfoLogLength;

    char const * sourcePointer = code.c_str();
    glShaderSource(shaderID, 1, &sourcePointer, NULL);
    glCompileShader(shaderID);

    // Check Vertex Shader
    glGetShaderiv(shaderID, GL_COMPILE_STATUS, &Result);
    glGetShaderiv(shaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
    if (InfoLogLength > 0)
    {
        std::vector<char> shaderErrorMessage(InfoLogLength + 1);
        glGetShaderInfoLog(shaderID, InfoLogLength, NULL, &shaderErrorMessage[0]);
        std::cerr << shaderErrorMessage[0] << std::endl;
        return false;
    }

    return true;
}

GLuint Display::linkShaderProgram(GLuint vertexShaderID, GLuint fragmentShaderID)
{
    GLint Result = GL_FALSE;
    int InfoLogLength;

    GLuint programID = glCreateProgram();
    glAttachShader(programID, vertexShaderID);
    glAttachShader(programID, fragmentShaderID);
    glLinkProgram(programID);

    // Check the program
    glGetProgramiv(programID, GL_LINK_STATUS, &Result);
    glGetProgramiv(programID, GL_INFO_LOG_LENGTH, &InfoLogLength);
    if (InfoLogLength > 0) {
        std::vector<char> ProgramErrorMessage(InfoLogLength + 1);
        glGetProgramInfoLog(programID, InfoLogLength, NULL, &ProgramErrorMessage[0]);
        std::cerr << ProgramErrorMessage[0] << std::endl;
        return -1;
    }

    return programID;
}