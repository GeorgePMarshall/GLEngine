#pragma once
#include <FbxLoader\FBXFile.h>
#include <iostream>
#include "ShaderProgram.h"
#include "BoundingVolumes.h"
#include "Camera.h"

class Mesh
{
	FBXFile* meshData;

	BoundingSphere* boundingSpheres;
	void RemoveBuffers();


public:
	glm::mat4 transform;

	~Mesh();

	void LoadMesh(const char* filePath);
	void CreateBuffers();

	void translate(vec3 position);
	void scale(float scalar);

	void Draw(Camera& camera, ShaderProgram& shader);


};

