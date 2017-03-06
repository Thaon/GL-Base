#include "Model.h"


Model::Model()
{
	m_mesh = new Mesh();
	m_texture = nullptr;
}

Model::Model(std::string name)
{
	m_mesh = new Mesh();
	m_name = name;
}


Model::~Model()
{
	delete m_shader;
	delete m_mesh;
}

void Model::LoadModelFromFile(std::string filename)
{
	m_mesh->LoadModelFromFile(filename);
}

void Model::SetMeshData(Vertex * vertices, unsigned int numVertices)
{
	m_vertsNumber = numVertices;
	m_verts = vertices;
	m_mesh->SetupMesh(m_verts, m_vertsNumber);
}

void Model::SetShader(std::string fileName)
{
	m_shader = new Shader(fileName);
}

void Model::SetTexture(Texture* texture)
{
	m_texture = texture;
}

void Model::Draw()
{
	m_shader->Bind();
	m_texture->Bind(0); //only draws albedo
	m_mesh->Draw();
}
