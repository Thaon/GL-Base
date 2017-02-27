#include "Texture.h"


Texture::Texture()
{
}

Texture::Texture(const char * fileName)
{
	m_image = CImg<unsigned char>(fileName);
	if (m_image == nullptr)
	{
		std::cout << "could not load the image: " << fileName << std::endl;
	}
}


Texture::~Texture()
{
	glDeleteTextures(1, &m_textureHandler);
	m_image.clear();
}

void Texture::Bind(unsigned int unit)
{
	glActiveTexture(GL_TEXTURE0 + unit); //set acitve texture unit
	glBindTexture(GL_TEXTURE_2D, m_textureHandler); //type of and texture to bind to unit

}

void Texture::CreateTexture()
{
	//generate texture buffer and bind texture to it
	glGenTextures(1, &m_textureHandler);
	glBindTexture(GL_TEXTURE_2D, m_textureHandler);
	
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); // wrap texture outside width
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); // wrap texture outside height
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); // linear filtering for minification (texture is smaller than area)
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); // linear filtering for magnification (texture is larger)

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, GetWidth(), GetHeight(), 0, GL_RGBA, GL_UNSIGNED_BYTE, m_image); //Target, Mipmapping Level, Pixel Format, Width, Height, Border Size, Input Format, Data Type of Texture, Our Images Data
}

