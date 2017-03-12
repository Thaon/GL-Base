#ifndef SHADER_H
#define SHADER_H

#include <string>
#include <GL\glew.h>

class Shader
{
public:
	Shader(const std::string& filename);
	Shader();
	void Bind(); //Set gpu to use our shaders

	std::string LoadShader(const std::string& fileName);
	void CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage);
	GLuint CreateShader(const std::string& text, unsigned int type);

	GLuint GetProgram() { return program; }

	~Shader();

private:
	static const unsigned int NUM_SHADERS = 2; // number of shaders
	Shader(const Shader& other) {}

	//http://en.cppreference.com/w/cpp/language/operators
	//void operator=(const Shader& other) {} //operator overloading REVIEW THIS!!!!!!!!!!!!!!!!!!

	GLuint program; // Track the shader program
	GLuint shaders[NUM_SHADERS]; //array of shaders
};

#endif
