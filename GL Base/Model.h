#ifndef MODEL_H
#define MODEL_H

#include "Mesh.h"
#include "Shader.h"
#include "Texture.h"

class Model
{
public:
	Model();
	Model(std::string name);
	~Model();

	void LoadModelFromFile(std::string filename);
	void SetMeshData(Vertex* vertices, unsigned int numVertices);
	void SetShader(std::string fileName);
	void SetName(std::string name) { m_name = name; }
	std::string GetName() { return m_name; }

	void SetTexture(Texture* texture);

	void Draw();

	void Move(glm::vec3 amount) { glTranslatef(amount.x, amount.y, amount.z); }
	void Rotate(float angle) { glRotatef(angle, 0, 1, 0); }
	void Scale(float amount) { glScalef(amount, amount, amount); }

private:
	std::string m_name;
	Shader* m_shader;
	Mesh* m_mesh;
	int m_vertsNumber;
	Vertex* m_verts;

	Texture * m_texture;
};

#endif
