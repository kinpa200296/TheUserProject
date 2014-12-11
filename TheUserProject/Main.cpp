#pragma once

#include "ProjectStd.h"
#include "Application.h"

using namespace TheUserProject;

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow)
{
	Application app(hInstance, nCmdShow);

	return app.Run();
}