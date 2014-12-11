#pragma once

#include "Edit.h"

namespace TheUserProject
{
	Edit::Edit(HINSTANCE hinst, HWND parent, int _x, int _y, int _width, int _height, int id, DWORD additionalStyles)
		: Window(hinst, parent, _x, _y, _width, _height, L"", WC_EDITW, NULL, 
				WS_CHILD | WS_VISIBLE | ES_LEFT | ES_AUTOHSCROLL | additionalStyles, (HMENU)id)
	{
	}

	Edit::~Edit()
	{
		DestroyWindow(window);
	}

	void Edit::Start()
	{
		create();
	}

	void Edit::SetText(WCHAR *text)
	{
		Edit_SetText(window, text);
	}

	void Edit::GetText(WCHAR *destination, int size)
	{
		Edit_GetText(window, destination, size);
	}

	int Edit::GetTextLength()
	{
		return Edit_GetTextLength(window);
	}
}