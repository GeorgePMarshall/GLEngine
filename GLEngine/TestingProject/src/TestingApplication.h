#pragma once
#include <Application.h>
#include <FlyCamera.h>
#include <ShaderProgram.h>
#include <Mesh.h>
#include <SpecularMaterial.h>
#include <ParticleEmitter.h>
#include <Input.h>
#include <Terrain.h>
#include <vector>
#include <gTime.h>

//testing aplication for my opengl engine




class TestingApplication : public Application
{
	void Initialize() override;
	void Update() override;
	void Draw() override;
	void Shutdown() override;

	FlyCamera camera;
	ShaderProgram shader;

	SpecularMaterial* material;
	ParticleEmitter emitter;
	Terrain terrain;

	Mesh* bunny;


	std::vector<glm::mat4> cats;

	GLuint i = 0;
};