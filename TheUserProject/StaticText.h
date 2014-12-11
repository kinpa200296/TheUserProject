#pragma once

#include "ProjectStd.h"

namespace TheUserProject
{
	class StaticText : public Window
	{
	public:
		StaticText(HINSTANCE hinst, HWND parent, int _x, int _y, int _width, int _height, int id, WCHAR *text, DWORD additionalStyles = 0);
		~StaticText();
		void Start();
		void SetText(WCHAR *text);

	private:
	};
}