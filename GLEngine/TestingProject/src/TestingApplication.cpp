#include "TestingApplication.h"
#include "Gizmos.h"

void TestingApplication::ThreadedLoad()
{

}

void TestingApplication::Load()
{

}



void TestingApplication::Initialize()
{
	lightDirection = vec3(0, 35, 0);

	ImGui_ImplGlfwGL3_Init(GetWindow(), false);
	ImGuiIO& io = ImGui::GetIO();
	io.DisplaySize.x = 1280;
	io.DisplaySize.x = 720;


	camera.LookAt(vec3(15), vec3(0), vec3(0, 1, 0));
	camera.setPerspective(glm::radians(80.f), 16 / 9.f);
	camera.initialize();

	shader.CreateShaderProgram("Specular.vert", "Specular.frag");
	
	
	terrain.Initialize(100, 100);
	emitter.Initialize();

	spear = new Mesh;
	spear->LoadMesh("data/soulspear/soulspear.fbx");
	spear->CreateBuffers();
	spearTextures.SetDiffuse("data/soulspear/soulspear_diffuse.tga");
	spearTextures.SetNormal("data/soulspear/soulspear_normal.tga");
	spearTextures.SetSpecular("data/soulspear/soulspear_specular.tga");

	spear->translate(vec3(20, 20, 20));
	spear->scale(5);

	
	ironMan = new Mesh;
	spear->LoadMesh("data/ironMan/ironman.fbx");
	spear->CreateBuffers();
	ironManTextures.SetDiffuse("data/ironMan/ironman.dff.png");
	ironManTextures.SetNormal("data/ironMan/ironman.norm.png");
	ironManTextures.SetSpecular("data/ironMan/ironmanr.spec.png");

	ironMan->translate(vec3(40, 17, 40));
	ironMan->transform = glm::rotate(ironMan->transform, glm::radians(90.0f), vec3(-1, 0, 0));
	ironMan->scale(5);
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

	if (Input::Input::getInput()->getKeyDown(GLFW_KEY_ESCAPE))
	{
		showUI = !showUI;
		camera.toggleMouseInput(GetWindow());
	}

}

void TestingApplication::Draw()
{
	//terrain
	terrain.draw(camera, glm::normalize(lightDirection));

	//models
	shader.setMat4("projectionView", camera.getProjectionViewTransform());

	shader.setFloat("time", gTime::Time());
	
	shader.setVec3("light.direction", glm::normalize(lightDirection));
	shader.setVec3("light.diffuse", vec3(1));
	shader.setVec3("light.specular", vec3(1));
	
	shader.setVec3("cameraPos", camera.getPosition());

	spearTextures.Bind(&shader);
	spear->Draw(camera, shader);

	ironManTextures.Bind(&shader);
	ironMan->Draw(camera, shader);

	//emitter
	emitter.position = lightDirection;
	emitter.Draw(camera);
	
	//gizmos
	//Gizmos::draw(camera.getProjectionViewTransform());

	//imgui
	if (showUI)
	{
		ImGui_ImplGlfwGL3_NewFrame();
		ImGui::Text("Push Escape to toggle gui");
		ImGui::DragFloat3("Light Direction + emmiter position", glm::value_ptr(lightDirection));
		ImGui::Render();
	}
}

void TestingApplication::Shutdown()
{
	ImGui_ImplGlfwGL3_Shutdown();
}