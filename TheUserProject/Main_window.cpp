#pragma once
#include "Main_window.h"

namespace TheUserProject
{
	Main_window::Main_window(HINSTANCE hinst, int nCmdShow, LPCWSTR app_title, LPCWSTR main_class) : 
		Window(hinst, NULL, 0, 0, 640, 480, app_title, main_class, WS_EX_CLIENTEDGE,
			(WS_OVERLAPPEDWINDOW ^ WS_MAXIMIZEBOX ^ WS_THICKFRAME) | WS_VISIBLE | WS_CLIPCHILDREN | WS_CLIPSIBLINGS )
	{
	}

	Main_window::~Main_window()
	{
	}

	void Main_window::Start()
	{
		RegisterWindowClass(CS_VREDRAW | CS_HREDRAW, (HBRUSH)(COLOR_WINDOW), app_inst, MAKEINTRESOURCEW(IDI_MAIN), 
					app_inst, MAKEINTRESOURCEW(IDI_MAIN));
		create();

		AddMessage(window, WM_CLOSE, this, To_funcpointer(&Main_window::OnClose));
		AddMessage(window, WM_COMMAND, this, To_funcpointer(&Main_window::OnCommand));
		AddMessage(window, WM_SIZE, this, To_funcpointer(&Main_window::OnResize));
	}

	void Main_window::Show(int nCmdShow)
	{
		ShowWindow(window, nCmdShow);
	}

	LRESULT Main_window::OnClose(WPARAM wParam, LPARAM lParam)
	{
		PostQuitMessage(0);
		return 0;
	}

	LRESULT Main_window::OnCommand(WPARAM wParam, LPARAM lParam)
	{
		int wmId = LOWORD(wParam), wmEvent = HIWORD(wParam);
		switch (wmId)
		{
		case ID_EXIT:
			return OnClose(wParam, lParam);
		default:
			break;
		}
		return 0;
	}

	LRESULT Main_window::OnResize(WPARAM wParam, LPARAM lParam)
	{
		width = LOWORD(lParam);
		height = HIWORD(lParam);
		return 0;
	}
}