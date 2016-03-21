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
#include <imgui\imgui.h>
#include <imgui\imgui_impl_glfw_gl3.h>

//testing aplication for my opengl engine




class TestingApplication : public Application
{
	void ThreadedLoad() override;
	void Load() override;
	void Initialize() override;
	void Update() override;
	void Draw() override;
	void Shutdown() override;

	FlyCamera camera;
	ShaderProgram shader;


	ParticleEmitter emitter;
	Terrain terrain;

	Mesh* spear;
	SpecularMaterial spearTextures;

	Mesh* ironMan;
	SpecularMaterial ironManTextures;

	bool showUI = true;

	std::vector<glm::mat4> cats;

	vec3 lightDirection;

	GLuint i = 0;
};