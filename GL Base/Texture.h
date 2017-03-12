#ifndef TEXTURE_H
#define TEXTURE_H

//using CIMG from: http://gli.g-truc.net/0.8.2/index.html

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <string>
#include <iostream>

#include <SOIL.h>

class Texture
{
public:
	Texture();
	~Texture();
	
	std::string m_name;
	std::string type;
	GLuint m_textureHandler;
	std::string path;  // We store the path of the texture to compare with other textures

private:
	glm::vec2 m_textureCoords;
};

#endif