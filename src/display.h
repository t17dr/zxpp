#ifndef DISPLAY_H
#define DISPLAY_H

#include <stdint.h>
#include <SDL.h>
#include "memory.h"
#include <vector>
#include <glew.h>

#include "utils.h"
#include "gl_utils.h"

#define DISPLAY_WIDTH 256
#define DISPLAY_HEIGHT 192

#define VERTEX_SHADER_FILE "shaders/vertex.glsl"
#define FRAGMENT_SHADER_FILE "shaders/fragment.glsl"

class Display {
    public:
        Display(Spectrum48KMemory* memory);
        ~Display();
        void draw(int windowWidth, int windowHeight);

        float getScale();
        void setScale(float scale);
    protected:
        // Vertex buffer for two triangles of the display
        void generateVertexBuffer();

        void generateUVs();

        bool compileShader(std::string code, GLuint shaderID);
        GLuint linkShaderProgram(GLuint vertexShaderID, GLuint fragmentShaderID);

        // Draw generated pixel buffer using openGL
        void glDraw(int windowWidth, int windowHeight);
    private:
        Spectrum48KMemory* m_memory;
        uint8_t m_pixels[DISPLAY_WIDTH*DISPLAY_HEIGHT*3];

        std::vector<GLfloat> m_vertexBuffer;
        std::vector<GLfloat> m_UVs;
        GLuint m_vaoID;
        GLuint m_vboID;
        GLuint m_programID;
        GLuint m_textureID;
        GLuint m_samplerID;
        GLuint m_uvID;

        float m_scale;

        // Are the flashing colors currently inverted?
        bool m_inverted;

        // Number of frames since last inversion of colors
        int m_frames;
};

#endif