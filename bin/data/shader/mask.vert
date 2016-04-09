// vertex shader
#version 150

void main(){
  gl_TexCoord[0] = gl_MultiTexCoord0;

  gl_Position = ftransform();
}
