#ifndef MODEL_H
#define MODEL_H

#include "Mesh.h"
#include "Shader.h"

class Model
{
public:
	Model();
	Model(std::string name);
	~Model();

	void SetMeshData(Vertex* vertices, unsigned int numVertices);
	void SetShader(std::string fileName);
	void SetName(std::string name) { m_name = name; }
	std::string GetName() { return m_name; }

	void Draw();

private:
	std::string m_name;
	Shader* m_shader;
	Mesh* m_mesh;
	int m_vertsNumber;
	Vertex* m_verts;
};

#endif
