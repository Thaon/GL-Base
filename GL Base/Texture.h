#ifndef TEXTURE_H
#define TEXTURE_H

//using CIMG from: http://gli.g-truc.net/0.8.2/index.html

#include <GL/glew.h>
#include <iostream>

#include <CImg.h>
using namespace cimg_library;

class Texture
{
public:
	Texture();
	Texture(const char * fileName);
	~Texture();
	
	void CreateTexture();
	void Bind(unsigned int unit);

	int GetHeight() { return m_image.height(); }
	int GetWidth() { return m_image.width(); }
	CImg<unsigned char>* GetImage() { return &m_image; }

private:
	GLuint m_textureHandler;
	CImg<unsigned char> m_image;
};

#endif