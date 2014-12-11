#pragma once

#include "ProjectStd.h"

namespace TheUserProject
{
	class FigureComboBox : public Window
	{
	public:
		void Start();
		void Fill();
		void GetCurrentSelectedText(WCHAR *destination, int size);
		FigureComboBox(HINSTANCE hinst, HWND parent, int _x, int _y, int _width, int _height, int id);
		~FigureComboBox();
		LRESULT OnCommand(WPARAM, LPARAM);
		LRESULT OnNotification(WPARAM, LPARAM);

	private:
	};
}