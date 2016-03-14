#include "gTime.h"

gTime* gTime::timeInstance = nullptr;


void gTime::Initialize()
{
	if (timeInstance == nullptr)
	{
		timeInstance = new gTime;
	}
}

void gTime::Update()
{
	curTime = (float)glfwGetTime();
	dt = curTime - prevTime;
	prevTime = curTime;
}

float gTime::deltaTime()
{
	return getInstance()->dt;
}


float gTime::Time()
{
	return getInstance()->curTime;
}

gTime* gTime::getInstance()
{
	return timeInstance;
}