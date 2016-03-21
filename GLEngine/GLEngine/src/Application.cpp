#include "Application.h"

void test() {}

int Application::Run()
{
	if (glfwInit() == false)
		return -1;

	window = glfwCreateWindow(1280, 720, "Not A Wondow", nullptr, nullptr);

	if (!window)
	{
		glfwTerminate();
		return -2;
	}

	glfwMakeContextCurrent(window);

	if (ogl_LoadFunctions() == ogl_LOAD_FAILED) {
		glfwDestroyWindow(window);
		glfwTerminate();
		return -3;
	}
	
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glClearColor(0.f, 0.1f, 0.2f, 1.f);

	Input::Initialize(window);
	gTime::Initialize();
	Initialize();

	std::thread loadingThread([this] { this->ThreadedLoad(); });


	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		
		gTime::getInstance()->Update();

		Update();
		Draw();

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	Shutdown();

	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}

GLFWwindow* Application::GetWindow()
{
	return window;
}
