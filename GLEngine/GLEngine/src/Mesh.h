#pragma once
#include <FbxLoader\FBXFile.h>
#include <iostream>
#include "ShaderProgram.h"
#include "BoundingVolumes.h"
#include "Camera.h"

class Mesh
{
	FBXFile* meshData;
	ShaderProgram* shader;

	BoundingSphere* boundingSpheres;

	void CreateBuffers();
	void RemoveBuffers();

public:
	glm::mat4 transform;

	Mesh(ShaderProgram* shader, const char* filePath);
	~Mesh();

	void translate(vec3 position);
	void scale(float scalar);

	void Draw(Camera& camera);


};

