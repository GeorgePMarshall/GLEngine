#pragma once
#include "gl_core_4_4.h"
#include <GLFW\glfw3.h>
#include <glm\glm.hpp>
#include <glm\ext.hpp>
#include <FbxLoader\FBXFile.h>
#include <climits>

using glm::vec3;
using glm::vec4;

class Frustrum
{
public:
	glm::vec4 planes[6];
	//ask about union??????

	//union
	//{
	//	glm::vec4 planes[6];
	//	
	//	struct
	//	{
	//		glm::vec4 m_right;
	//		glm::vec4 m_left;
	//		glm::vec4 m_top;
	//		glm::vec4 m_bottom;
	//		glm::vec4 m_far;
	//		glm::vec4 m_near;
	//	};
	//
	//};

	void calculateFrustrum(glm::mat4& projectionView);

};

class BoundingSphere
{
	glm::vec3 center;
	float radius;

public:
	void calculateSphere(FBXMeshNode* mesh);
	bool isColliding(BoundingSphere* other);
	bool isColliding(Frustrum& frustrum);

};
