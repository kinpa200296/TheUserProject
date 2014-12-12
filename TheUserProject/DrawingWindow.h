#pragma once

#include "ProjectStd.h"

namespace TheUserProject
{
	class DrawingWindow : Window
	{
	public:
		DrawingWindow(HINSTANCE hinst, HWND parent, int _x, int _y, int _width, int _height, User user);
		~DrawingWindow();
		void Start();
		LRESULT OnPaint(WPARAM, LPARAM);
	private:
		User _user;
	};
}