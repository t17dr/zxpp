#version 330 core

in vec2 UV;
out vec4 color;
uniform sampler2D inTexture;

void main() {
    color = texture(inTexture, UV).rgba;
}
