#include "Mesh.h"


Mesh::Mesh()
{
	m_VBO = 0;
	m_VAO = 0;

	m_NumberOfVertices = 0;

	indices = std::vector<int>();
	verts = std::vector<Vertex>();
	m_positions = std::vector<glm::vec3>();
	m_textCoords = std::vector<glm::vec2>();
}

void Mesh::SetupMesh(Vertex* vertices, unsigned int numVertices)
{
	/*m_NumberOfVertices = numVertices;
	glGenVertexArrays(1, &m_vertexArrayObject);
	glBindVertexArray(m_vertexArrayObject);
	glGenBuffers(NUM_BUFFERS, m_vertexArrayBuffers);
	glBindBuffer(GL_ARRAY_BUFFER, m_vertexArrayBuffers[POSITION_VERTEXBUFFER]);
	glBufferData(GL_ARRAY_BUFFER, numVertices * sizeof(vertices[0]), vertices, GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glBindVertexArray(0);*/

	glGenBuffers(NUM_BUFFERS, m_vertexArrayBuffers); //generate our buffers based of our array of data/buffers - GLuint vertexArrayBuffers[NUM_BUFFERS];
	glBindBuffer(GL_ARRAY_BUFFER, m_vertexArrayBuffers[POSITION_VERTEXBUFFER]); //tell opengl what type of data the buffer is (GL_ARRAY_BUFFER), and pass the data
	glBufferData(GL_ARRAY_BUFFER, numVertices * sizeof(m_positions[0]), &m_positions[0], GL_STATIC_DRAW); //move the data to the GPU - type of data, size of data, starting address (pointer) of data, where do we store the data on the GPU

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

	glBindBuffer(GL_ARRAY_BUFFER, m_vertexArrayBuffers[TEXCOORD_VB]); //tell opengl what type of data the buffer is (GL_ARRAY_BUFFER), and pass the data
	glBufferData(GL_ARRAY_BUFFER, numVertices * sizeof(m_textCoords[0]), &m_textCoords[0], GL_STATIC_DRAW); //move the data to the GPU - type of data, size of data, starting address (pointer) of data, where do we store the data on the GPU

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, 0);

	glBindVertexArray(0); // unbind our VAO

}

bool Mesh::LoadModelFromFile(std::string filename)
{
	std::cout << "Attempting to load model "<< filename << std::endl;
	const aiVector3D Zero3D(0.0f, 0.0f, 0.0f);

	const aiScene* scene = aiImportFile(filename.c_str(), aiProcess_JoinIdenticalVertices | aiProcess_Triangulate | aiProcess_FlipUVs | aiProcess_GenSmoothNormals);

	if (scene)
	{
		std::cout << "Parsing Model " << filename << std::endl;
		const aiMesh * mesh = scene->mMeshes[0];

		std::vector<int> indices;
		std::vector<Vertex> verts;

		for (int f = 0; f < mesh->mNumFaces; f++)
		{
			const aiFace * face = &mesh->mFaces[f];
			for (int i = 0; i < face->mNumIndices; i++)
			{
				int index = face->mIndices[i];
				indices.push_back(index);

				Vertex ourV;

				//get data and convert it to glm format
				aiVector3D pos = mesh->mVertices[face->mIndices[i]];
				glm::vec3 glmPos = glm::vec3(pos.x, pos.y, pos.z);
				m_positions.push_back(glmPos);

				aiVector3D uv = mesh->mTextureCoords[0][face->mIndices[i]];
				glm::vec2 glmUV = glm::vec2(uv.x, uv.z);
				m_textCoords.push_back(glmUV);

				aiVector3D normal = mesh->mNormals[face->mIndices[i]];
				glm::vec3 glmNormal = glm::vec3(normal.x, normal.y, normal.z);

				ourV.position = glmPos;

				verts.push_back(ourV);
			}
		}

		CopyVertexData(&verts[0], verts.size(), &indices[0], indices.size());
	}
	else
	{
		std::cout << "Error Parsing Model " << aiGetErrorString() << std::endl;
	}

	aiReleaseImport(scene);
	return true;
}

Mesh::~Mesh()
{
	glDeleteVertexArrays(1, &m_VAO);
	glDeleteBuffers(1, &m_VBO);
	glDeleteBuffers(1, &m_ElementBuffer);
	glDeleteVertexArrays(1, &m_vertexArrayObject);
}

void Mesh::Draw()
{
	glBindBuffer(GL_ARRAY_BUFFER, m_VBO);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ElementBuffer);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void**)offsetof(Vertex, position));

	glDrawElements(GL_TRIANGLES, m_NumberOfIndices, GL_UNSIGNED_INT, nullptr);
	/*glBindVertexArray(m_vertexArrayObject);
	glDrawArrays(GL_TRIANGLES, 0, m_NumberOfVertices);
	glBindVertexArray(0);*/
}

void Mesh::CopyVertexData(Vertex * pVerts, int numberOfVertices, int * indicesArray, int index)
{
	glGenBuffers(1, &m_VBO);
	glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
	glBufferData(GL_ARRAY_BUFFER, numberOfVertices * sizeof(Vertex), pVerts, GL_STATIC_DRAW);

	glGenBuffers(1, &m_ElementBuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ElementBuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, index * sizeof(unsigned int), &indicesArray[0], GL_STATIC_DRAW);

	glGenVertexArrays(1, &m_VAO);
	glBindVertexArray(m_VAO);
	glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ElementBuffer);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void**)offsetof(Vertex, position));

	//will reuse when application becomes more complex
	/*glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void**)offsetof(Vertex, colour));

	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void**)offsetof(Vertex, texCoords));

	glEnableVertexAttribArray(3);
	glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void**)offsetof(Vertex, vertexNormal));

	glEnableVertexAttribArray(4);
	glVertexAttribPointer(4, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void**)offsetof(Vertex, tangent));

	glEnableVertexAttribArray(5);
	glVertexAttribPointer(5, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void**)offsetof(Vertex, binormal));*/

	m_NumberOfVertices = numberOfVertices;
	m_NumberOfIndices = index;
}
