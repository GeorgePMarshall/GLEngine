#pragma once
#include "gl_core_4_4.h"
#include <GLFW\glfw3.h>
#include <glm\glm.hpp>
#include "ShaderProgram.h"
#include "Camera.h"
#include "Texture.h"
#include "SpecularMaterial.h"

using glm::vec2;
using glm::vec3;

struct Vertex
{
	vec3 position;
	vec3 normal;
	vec2 texCoord;
};

class Terrain
{
	ShaderProgram shader;
	Texture* heightMap;
	SpecularMaterial baseTexture;
	SpecularMaterial peakTexture;

	GLuint VAO, VBO, EBO;
	GLuint rows, cols;

	GLfloat timer = 0;
	
	void GenerateGrid();
	void GenerateHeightMapTexture();
	GLfloat* GenerateHeightMap();

public:

	void Initialize(GLuint rows, GLuint cols);
	void draw(Camera* camera);



};

