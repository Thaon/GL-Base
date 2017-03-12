#ifndef MESH_H
#define MESH_H

#include <iostream>
#include <vector>
#include <glm\glm.hpp>
#include <GL\glew.h>

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include "Shader.h"
#include "Texture.h"

class Vertex
{
public:
	Vertex() {}

	glm::vec3 position;
	glm::vec3 normal;
	glm::vec2 texCoords;
protected:
private:
};

class Mesh
{
public:
	void SetupMesh();
	Mesh();
	Mesh(std::vector<Vertex> vertices, std::vector<GLuint> indices, std::vector<Texture> textures);
	~Mesh();

	void Draw(Shader* shader);
private:

	enum
	{
		POSITION_VERTEXBUFFER,
		TEXCOORD_VB,
		NUM_BUFFERS
	};

	GLuint m_VBO;
	GLuint m_VAO;
	GLuint m_EBO;
	std::vector<GLuint> indices;
	std::vector<Vertex> verts;

	std::vector<glm::vec3> m_positions;
	std::vector<glm::vec2> m_textCoords;

	std::vector<Texture> textures;

	unsigned int m_NumberOfVertices, m_NumberOfIndices; //how much of the vertexArrayObject do we want to draw
};


#endif
