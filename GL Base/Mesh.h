#ifndef MESH_H
#define MESH_H

#include <iostream>
#include <vector>
#include <glm\glm.hpp>
#include <GL\glew.h>

#include <assimp/cimport.h>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

class Vertex
{
public:
	Vertex() {}

	glm::vec3 position;
protected:
private:
};

class Mesh
{
public:
	bool LoadModelFromFile(std::string filename);

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

	GLuint m_VBO;
	GLuint m_VAO;
	GLuint m_ElementBuffer;
	std::vector<int> indices;
	std::vector<Vertex> verts;
	unsigned int m_NumberOfVertices, m_NumberOfIndices; //how much of the vertexArrayObject do we want to draw

	//taken from GP2 coursework at: https://github.com/OliverJayMorrison/GP-Coursework/blob/master/Dingleberry/src/MeshRenderer.cpp
	void CopyVertexData(Vertex * pVerts, int numberOfVertices, int *indicesArray, int index);
};


#endif
