#include "Model.h"


Model::Model()
{
}

Model::Model(std::string name)
{
	m_name = name;
}


Model::~Model()
{
	delete m_shader;
	delete m_mesh;
}

void Model::SetMeshData(Vertex * vertices, unsigned int numVertices)
{
	m_vertsNumber = numVertices;
	m_verts = vertices;
	m_mesh = new Mesh();
	m_mesh->SetupMesh(m_verts, m_vertsNumber);
}

void Model::SetShader(std::string fileName)
{
	m_shader = new Shader(fileName);
}

void Model::Draw()
{
	m_shader->Bind();
	m_mesh->Draw();
}
