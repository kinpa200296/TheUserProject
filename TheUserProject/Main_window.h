#pragma once

#include "ProjectStd.h"

namespace TheUserProject
{
	class Main_window : public Window
	{
	public:
		Main_window(HINSTANCE hinst, int nCmdShow, LPCWSTR app_title, LPCWSTR main_class);
		~Main_window();
	//	registers, creates window and adds necessary messages
		void Start();
	//	shows window
	//	should be called after all child windows have been created
		void Show(int nCmdShow);

	//	processes message WM_CLOSE
		LRESULT OnClose(WPARAM, LPARAM);
	//	processes message WM_COMMAND
		LRESULT OnCommand(WPARAM, LPARAM);
	//	processes message WM_SIZE
		LRESULT OnResize(WPARAM, LPARAM);

	private:

	};
}