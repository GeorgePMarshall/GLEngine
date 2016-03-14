#include "TestingApplication.h"

void TestingApplication::Initialize()
{
	camera.LookAt(vec3(15), vec3(0), vec3(0, 1, 0));
	camera.setPerspective(glm::radians(80.f), 16 / 9.f);
	camera.initialize();

	shader.CreateShaderProgram("Specular.vert", "Specular.frag");
	
	
	terrain.Initialize(100, 100);
	emitter.Initialize();

	bunny = new Mesh(&shader, "data/Bunny.fbx");

}

void TestingApplication::Update()
{
	if (Input::getInput()->getKey(GLFW_KEY_T))
	{
		++i;
		if (i >= cats.size())
			i = 0;
		camera.setWorldTransform(cats[i]);
	}
	else if(Input::getInput()->getKey(GLFW_KEY_R))
	{
		camera.update();
		cats.push_back(camera.getWorldTransform());
	}
	else
	{
		camera.update();
	}
}

void TestingApplication::Draw()
{
	shader.setMat4("projectionView", camera.getProjectionViewTransform());

	shader.setFloat("time", gTime::Time());
	
	shader.setVec3("light.direction", vec3(0.2f));
	shader.setVec3("light.diffuse", vec3(1));
	shader.setVec3("light.specular", vec3(1));
	
	shader.setVec3("cameraPos", camera.getPosition());

	emitter.Draw((Camera*)&camera);
	

	terrain.draw((Camera*)&camera);

	bunny->Draw(camera);
}

void TestingApplication::Shutdown()
{
}