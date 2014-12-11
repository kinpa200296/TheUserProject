#pragma once

#include "ProjectStd.h"
#include "Main_window.h"

namespace TheUserProject
{
	class Application
	{
	//	current application instance
		HINSTANCE app_inst;
		WCHAR main_class[MAXSTRING], app_title[MAXSTRING];
	//	parametr indentifying how to show window at first
		int nCmdShow;
		Main_window *global_window;
	public:
		Application(HINSTANCE hinst, int ncmdshow);
		~Application();
	//
	//	Starts global message cycle
	//
		int Run();

	//
	//	Creates all windows in the application
	//	editable
	//
		void Create_windows();

	private:

	};
}