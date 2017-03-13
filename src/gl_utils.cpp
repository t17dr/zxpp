
#include "gl_utils.h"

mat4 projectionOrtho(GLfloat width, GLfloat height, GLfloat near, GLfloat far)
{
    mat4 mat = {
        1.0f / (width/2.0f), 0, 0, 0,
        0, 1.0f / (height/2.0f), 0, 0,
        0, 0, -2.0f / (far - near), 0,
        0, 0, 0, 1
    };
    return mat;
}

mat4 identityMatrix()
{
    mat4 mat = { 1, 0, 0, 0,
                 0, 1, 0, 0,
                 0, 0, 1, 0,
                 0, 0, 0, 1 };
    return mat;
}

mat4 multiply(mat4 a, mat4 b)
{
    mat4 mat = {
          a[0]*b[0]+a[4]*b[1]+a[8]*b[2]+a[12]*b[3],
          a[1]*b[0]+a[5]*b[1]+a[9]*b[2]+a[13]*b[3],
          a[2]*b[0]+a[6]*b[1]+a[10]*b[2]+a[14]*b[3],
          a[3]*b[0]+a[7]*b[1]+a[11]*b[2]+a[15]*b[3]
        ,
          a[0]*b[4]+a[4]*b[5]+a[8]*b[6]+a[12]*b[7],
          a[1]*b[4]+a[5]*b[5]+a[9]*b[6]+a[13]*b[7],
          a[2]*b[4]+a[6]*b[5]+a[10]*b[6]+a[14]*b[7],
          a[3]*b[4]+a[7]*b[5]+a[11]*b[6]+a[15]*b[7]
        ,
          a[0]*b[8]+a[4]*b[9]+a[8]*b[10]+a[12]*b[11],
          a[1]*b[8]+a[5]*b[9]+a[9]*b[10]+a[13]*b[11],
          a[2]*b[8]+a[6]*b[9]+a[10]*b[10]+a[14]*b[11],
          a[3]*b[8]+a[7]*b[9]+a[11]*b[10]+a[15]*b[11]
        ,
          a[0]*b[12]+a[4]*b[13]+a[8]*b[14]+a[12]*b[15],
          a[1]*b[12]+a[5]*b[13]+a[9]*b[14]+a[13]*b[15],
          a[2]*b[12]+a[6]*b[13]+a[10]*b[14]+a[14]*b[15],
          a[3]*b[12]+a[7]*b[13]+a[11]*b[14]+a[15]*b[15]
    };
    return mat;
}

mat4 scaleMatrix(float x, float y)
{
    mat4 mat = {
        x, 0, 0, 0,
        0, y, 0, 0,
        0, 0, 1, 0,
        0, 0, 0, 1
    };
    return mat;
}

void _glLogLastError(int line, char* file)
{
    GLenum err = glGetError();
    switch (err)
    {
        case GL_NO_ERROR: break;
        case GL_INVALID_ENUM: std::cerr << "GL_INVALID_ENUM in " << file << ":" << line << std::endl; break;
        case GL_INVALID_VALUE: std::cerr << "GL_INVALID_VALUE in " << file << ":" << line << std::endl; break;
        case GL_INVALID_OPERATION: std::cerr << "GL_INVALID_OPERATION in " << file << ":" << line << std::endl; break;
        case GL_STACK_OVERFLOW: std::cerr << "GL_STACK_OVERFLOW in " << file << ":" << line << std::endl; break;
        case GL_STACK_UNDERFLOW: std::cerr << "GL_STACK_UNDERFLOW in " << file << ":" << line << std::endl; break;
        case GL_OUT_OF_MEMORY: std::cerr << "GL_OUT_OF_MEMORY in " << file << ":" << line << std::endl; break;
        case GL_TABLE_TOO_LARGE: std::cerr << "GL_TABLE_TOO_LARGE in " << file << ":" << line << std::endl; break;
        default: std::cerr << "Unknown openGL error in " << file << ":" << line << std::endl; break;
    }
}