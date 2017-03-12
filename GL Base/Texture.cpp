#include "Texture.h"


Texture::Texture()
{
}


Texture::~Texture()
{
	glDeleteTextures(1, &m_textureHandler);
}

