#pragma once

#include "Button.h"

namespace TheUserProject
{
	Button::Button(HINSTANCE hinst, HWND parent, int _x, int _y, int _width, int _height, int id, WCHAR *text, DWORD additionalStyles)
		: Window(hinst, parent, _x, _y, _width, _height, text, WC_BUTTONW, NULL, 
		WS_BORDER | WS_CHILD | WS_VISIBLE | BS_CENTER | BS_VCENTER | BS_DEFPUSHBUTTON | BS_TEXT | additionalStyles, (HMENU)id)
	{
	}

	Button::~Button()
	{
		DestroyWindow(window);
	}

	void Button::Start()
	{
		create();
	}

	void Button::SetText(WCHAR *text)
	{
		Button_SetText(window, text);
	}
}