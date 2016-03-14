#pragma once
#include <FbxLoader\FBXFile.h>
#include <iostream>
#include "ShaderProgram.h"
#include "BoundingVolumes.h"
#include "Camera.h"

class Mesh
{
	FBXFile* meshData;
	glm::mat4 transform;
	ShaderProgram* shader;

	BoundingSphere* boundingSpheres;

	void CreateBuffers();
	void RemoveBuffers();

public:

	Mesh(ShaderProgram* shader, const char* filePath);
	~Mesh();
	void Draw(Camera& camera);


};

