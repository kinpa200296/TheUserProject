#pragma once

#include "ProjectStd.h"

namespace TheUserProject
{
	class Button : public Window
	{
	public:
		Button(HINSTANCE hinst, HWND parent, int _x, int _y, int _width, int _height, int id, WCHAR *text, DWORD additionalStyles = 0);
		~Button();
		void Start();
		void SetText(WCHAR *text);

	private:
	};
}