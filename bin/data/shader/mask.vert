// vertex shader

#version 130

uniform mat4 modelViewProjectionMatrix;
in vec4 position;
in vec2 texcoord;

out vec2 texVarying;

void main(){
  texVarying = texcoord;

  gl_Position = modelViewProjectionMatrix * position;
}