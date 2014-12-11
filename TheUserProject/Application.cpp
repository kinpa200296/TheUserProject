#include "Application.h"

namespace TheUserProject
{
	Application::Application(HINSTANCE hinst, int ncmdshow)
	{
		app_inst = hinst;
		nCmdShow = ncmdshow;
		LoadStringW(hinst, IDS_APP_TITLE, app_title, MAXSTRING);
		LoadStringW(hinst, IDS_MAIN_CLASS, main_class, MAXSTRING);
	}

	Application::~Application()
	{
		global_window->~Main_window();
	}

	void Application::Create_windows()
	{
		global_window = new Main_window(app_inst, nCmdShow, app_title, main_class);
		global_window->Start();
	}

	int Application::Run()
	{
		MSG msg;
		HACCEL hAccelTable;

		hAccelTable = LoadAccelerators(app_inst, MAKEINTRESOURCE(IDR_ACCELERATORS));

		Create_windows();
		global_window->Show(nCmdShow);

		while (GetMessage(&msg, NULL, 0, 0))
		{
			if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
				//global_window->WndProc(msg.hwnd, msg.message, msg.wParam, msg.lParam);
			}
		}

		Window::global_message_map.clear();

		return (int) msg.wParam;
	}
}