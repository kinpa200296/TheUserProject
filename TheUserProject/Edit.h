#pragma once

#include "ProjectStd.h"

namespace TheUserProject
{
	class Edit : public Window
	{
	public:
		Edit(HINSTANCE hinst, HWND parent, int _x, int _y, int _width, int _height, int id, DWORD additionalStyles = 0);
		~Edit();
		void Start();
		void SetText(WCHAR *text);
		void GetText(WCHAR *destination, int size);
		int GetTextLength();
		void Clear();

	private:
	};
}