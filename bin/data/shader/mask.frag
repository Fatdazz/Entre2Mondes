// fragment shader

#version 330

out vec4 outputColor;

uniform sampler2DRect mask;
uniform sampler2DRect tex;

in vec2 texVarying;

void main() {
  vec3 texRGB = texture2DRect(tex, texVarying).rgb;
  vec3 maskRGB = texture2DRect(mask, texVarying).rgb;
  outputColor = vec4(texRGB, maskRGB.r);
	
}
