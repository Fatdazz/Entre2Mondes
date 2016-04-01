// fragment shader

uniform sampler2DRect mask;
uniform sampler2DRect tex;

in vec2 texVarying;

void main() {
  vec3 texRGB = texture2DRect(tex, gl_TexCoord[0].st).rgb;
  vec3 maskRGB = texture2DRect(mask, gl_TexCoord[0].st).rgb;
  gl_FragData[0] = vec4(texRGB, maskRGB.r);
	
}
