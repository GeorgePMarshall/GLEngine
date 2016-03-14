#pragma once
#include "ShaderProgram.h"
#include "Camera.h"
#include "gTime.h"

struct Particle
{
	glm::vec3 position;
	glm::vec3 velocity;
	float lifeSpan;
	float lifeTime;
};



class ParticleEmitter
{
	ShaderProgram drawShader;
	ShaderProgram updateShader;
	
	void CreateBuffers();



protected:

	GLuint activeBuffer, vao[2], vbo[2];

	Particle* particles;	
	GLuint maxParticles;
	
	glm::vec3 position;

	float minLifeSpan, maxLifeSpan;
	float startSize, endSize;
	float minVelocity, maxVelocity;

	glm::vec4 startColour, EndColour;

	float lastDrawTime;


public:

	~ParticleEmitter();
	void Initialize();
	void Draw(Camera* camera);







};