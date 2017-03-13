#version 330 core

in vec2 TexCoords;

out vec4 color;

uniform sampler2D texture_diffuse1;

void main(){
	//gl_FragColor = vec4(1.0, 0.0, 0.0, 1.0);
	color = vec4(texture(texture_diffuse1, TexCoords));
}