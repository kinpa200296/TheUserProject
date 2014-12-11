#pragma once

#include "StaticText.h"

namespace TheUserProject
{
	StaticText::StaticText(HINSTANCE hinst, HWND parent, int _x, int _y, int _width, int _height, int id, WCHAR *text, DWORD additionalStyles)
		: Window(hinst, parent, _x, _y, _width, _height, text, WC_STATICW, NULL, 
		WS_CHILD | WS_VISIBLE | additionalStyles, (HMENU)id)
	{
	}

	StaticText::~StaticText()
	{
		DestroyWindow(window);
	}

	void StaticText::Start()
	{
		create();
	}

	void StaticText::SetText(WCHAR *text)
	{
		Static_SetText(window, text);
	}
}