#include "display.h"

Display::Display(Spectrum48KMemory* memory)
    : m_memory(memory),
      m_inverted(false),
      m_frames(0),
      m_scale(2.0f)
{
    // TODO: error handling
    generateVertexBuffer();
    generateUVs();

    glGenVertexArrays(1, &m_vaoID);
    glLogLastError();
    glBindVertexArray(m_vaoID);
    glLogLastError();
    glGenBuffers(1, &m_vboID); // vertices
    glLogLastError();
    glBindBuffer(GL_ARRAY_BUFFER, m_vboID);
    glLogLastError();
    glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * m_vertexBuffer.size(), m_vertexBuffer.data(), GL_STATIC_DRAW);
    glLogLastError();
    glGenBuffers(1, &m_uvID);   // UVs
    glLogLastError();
    glBindBuffer(GL_ARRAY_BUFFER, m_uvID);
    glLogLastError();
    glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * m_UVs.size(), m_UVs.data(), GL_STATIC_DRAW);
    glLogLastError();

    glGenTextures(1, &m_textureID);
    glLogLastError();
    glBindTexture(GL_TEXTURE_2D, m_textureID);
    glLogLastError();
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT );
    glLogLastError();
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT );
    glLogLastError();
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST );
    glLogLastError();
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST );
    glLogLastError();
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, DISPLAY_WIDTH, DISPLAY_HEIGHT, 0, GL_BGR, GL_UNSIGNED_BYTE, m_pixels);
    glLogLastError();

    GLuint vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
    GLuint fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
    std::string vertexShaderCode = readFileToString(VERTEX_SHADER_FILE);
    std::string fragmentShaderCode = readFileToString(FRAGMENT_SHADER_FILE);
    compileShader(vertexShaderCode, vertexShaderID);
    glLogLastError();
    compileShader(fragmentShaderCode, fragmentShaderID);
    glLogLastError();
    GLuint programID = linkShaderProgram(vertexShaderID, fragmentShaderID);
    glLogLastError();
    glDetachShader(programID, vertexShaderID);
    glLogLastError();
    glDetachShader(programID, fragmentShaderID);
    glLogLastError();

    glDeleteShader(vertexShaderID);
    glLogLastError();
    glDeleteShader(fragmentShaderID);
    glLogLastError();

    m_samplerID = glGetUniformLocation(programID, "inTexture");

    std::cout << "OpenGL buffers initialized" << std::endl;
    glLogLastError();

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
        scaleMatrix(m_scale, m_scale));

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
    std::cout << "Display size: " << DISPLAY_WIDTH << " x " << DISPLAY_HEIGHT << std::endl;

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
    std::cout << "Compiling " << code.c_str() << "..." << std::endl;

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

    std::cout << "Success" << std::endl;

    return true;
}

GLuint Display::linkShaderProgram(GLuint vertexShaderID, GLuint fragmentShaderID)
{
    std::cout << "Linking shader program..." << std::endl;
    GLint Result = GL_FALSE;
    int InfoLogLength;

    GLuint programID = glCreateProgram();
    glLogLastError();
    glAttachShader(programID, vertexShaderID);
    glLogLastError();
    glAttachShader(programID, fragmentShaderID);
    glLogLastError();
    glLinkProgram(programID);
    glLogLastError();

    // Check the program
    glGetProgramiv(programID, GL_LINK_STATUS, &Result);
    if (Result == GL_FALSE) { std::cerr << "Link error" << std::endl; }
    glGetProgramiv(programID, GL_INFO_LOG_LENGTH, &InfoLogLength);
    if (InfoLogLength > 0) {
        std::vector<char> ProgramErrorMessage(InfoLogLength + 1);
        glGetProgramInfoLog(programID, InfoLogLength, NULL, &ProgramErrorMessage[0]);
        std::cerr << "Error: " << ProgramErrorMessage[0] << std::endl;
        return -1;
    }
    std::cout << "Successful" << std::endl;

    return programID;
}

float Display::getScale()
{
    return m_scale;
}

void Display::setScale(float scale)
{
    m_scale = scale;
}