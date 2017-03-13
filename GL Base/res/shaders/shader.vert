#version 330 core

attribute vec3 position;
attribute vec2 texCoords;

uniform mat4 M;
uniform mat4 V;
uniform mat4 P;

out vec2 TexCoords;

void main(){
	//gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;
	gl_Position = M * V * P * vec4(position, 1.0f);
	TexCoords = texCoords;
}