#ifndef MESH_H
#define MESH_H

#include <glm\glm.hpp>
#include <GL\glew.h>

class Vertex
{
public:
	Vertex(const glm::vec3& pos)
	{
		this->pos = pos;
	}
protected:
private:
	glm::vec3 pos;
};

class Mesh
{
public:
	Mesh(Vertex* vertices, unsigned int numVertices);
	~Mesh();

	void Draw();
private:

	enum
	{
		POSITION_VERTEXBUFFER,
		NUM_BUFFERS
	};

	GLuint m_vertexArrayObject;
	GLuint m_vertexArrayBuffers[NUM_BUFFERS]; // create our array of buffers
	unsigned int m_drawCount; //how much of the vertexArrayObject do we want to draw
};


#endif
