#pragma once

#include "ProjectStd.h"

namespace TheUserProject
{
	class SongComboBox : public Window
	{
	public:
		void Start();
		void Fill(SongManager music);
		void GetCurrentSelectedText(WCHAR *destination, int size);
		SongComboBox(HINSTANCE hinst, HWND parent, int _x, int _y, int _width, int _height, int id);
		~SongComboBox();
		LRESULT OnCommand(WPARAM, LPARAM);
		LRESULT OnNotification(WPARAM, LPARAM);

	private:
	};
}