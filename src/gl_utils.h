#pragma once

#include <glew.h>
#include <vector>
#include <iostream>

typedef std::vector<GLfloat> mat4;

// Get projection matrix for orthographic viewport
mat4 projectionOrtho(GLfloat width, GLfloat height, GLfloat near, GLfloat far);

mat4 identityMatrix();
mat4 scaleMatrix(float x, float y);

mat4 multiply(mat4 a, mat4 b);

#define glLogLastError() _glLogLastError(__LINE__, __FILE__)

void _glLogLastError(int line, char* file);