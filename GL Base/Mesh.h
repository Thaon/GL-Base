#ifndef MESH_H
#define MESH_H

#include <glm\glm.hpp>
#include <GL\glew.h>

//assimp integration from: http://www.mbsoftworks.sk/index.php?page=tutorials&series=1&tutorial=23
#include <assimp/Importer.hpp>      // C++ importer interface
#include <assimp/scene.h>           // Output data structure
#include <assimp/postprocess.h>     // Post processing fla

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
	void SetupMesh(Vertex* vertices, unsigned int numVertices);
	Mesh();
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
