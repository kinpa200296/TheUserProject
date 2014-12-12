#include "SongComboBox.h"

namespace TheUserProject
{
	SongComboBox::SongComboBox(HINSTANCE hinst, HWND parent, int _x, int _y, int _width, int _height, int id) : Window(hinst, parent,
				_x, _y, _width, _height, NULL, WC_COMBOBOXW, NULL, 
				WS_BORDER | WS_CHILD | WS_VISIBLE | CBS_SIMPLE | CBS_HASSTRINGS | CBS_DROPDOWN | WS_VSCROLL, (HMENU)id)
	{
	}

	SongComboBox::~SongComboBox()
	{
		DestroyWindow(window);
	}

	void SongComboBox::Start()
	{
		create();

		AddMessage(window, WM_COMMAND, this, To_funcpointer(&SongComboBox::OnCommand));
		AddMessage(window, WM_NOTIFY, this, To_funcpointer(&SongComboBox::OnNotification));
	}

	void SongComboBox::Fill(SongManager *music)
	{
		ComboBox_ResetContent(window);
		for (int i = 0; i < music->GetSongsCount(); i++)
		{
			ComboBox_AddString(window, music->GetSong(i));
		}
		ComboBox_SetCurSel(window, 0);
	}

	void SongComboBox::GetCurrentSelectedText(WCHAR *destination, int size)
	{
		int pos = ComboBox_GetCurSel(window);
		ComboBox_GetText(window, destination, size);
	}

	LRESULT SongComboBox::OnCommand(WPARAM wParam, LPARAM lParam)
	{
		int wmId = LOWORD(wParam), wmEvent = HIWORD(wParam);
		switch (wmEvent)
		{
		default:
			break;
		}
		return 0;
	}

	LRESULT SongComboBox::OnNotification(WPARAM wParam, LPARAM lParam)
	{
		MessageBox(parent, L"Got Notification for SongComboBox", L"Error", MB_OK);
		return 0;
	}
}