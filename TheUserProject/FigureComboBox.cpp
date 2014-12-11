#include "FigureComboBox.h"

namespace TheUserProject
{
	FigureComboBox::FigureComboBox(HINSTANCE hinst, HWND parent, int _x, int _y, int _width, int _height, int id) : Window(hinst, parent,
				_x, _y, _width, _height, NULL, WC_COMBOBOXW, NULL, 
				WS_BORDER | WS_CHILD | WS_VISIBLE | CBS_SIMPLE | CBS_HASSTRINGS | CBS_DROPDOWN | WS_VSCROLL, (HMENU)id)
	{
	}

	FigureComboBox::~FigureComboBox()
	{
		DestroyWindow(window);
	}

	void FigureComboBox::Start()
	{
		create();

		AddMessage(window, WM_COMMAND, this, To_funcpointer(&FigureComboBox::OnCommand));
		AddMessage(window, WM_NOTIFY, this, To_funcpointer(&FigureComboBox::OnNotification));
	}

	void FigureComboBox::Fill()
	{
		ComboBox_ResetContent(window);
		ComboBox_AddString(window, L"Triangle");
		ComboBox_AddString(window, L"Square");
		ComboBox_AddString(window, L"Circle");
		ComboBox_SetCurSel(window, 0);
	}

	void FigureComboBox::GetCurrentSelectedText(WCHAR *destination, int size)
	{
		int pos = ComboBox_GetCurSel(window);
		ComboBox_GetText(window, destination, size);
	}

	LRESULT FigureComboBox::OnCommand(WPARAM wParam, LPARAM lParam)
	{
		int wmId = LOWORD(wParam), wmEvent = HIWORD(wParam);
		switch (wmEvent)
		{
		default:
			break;
		}
		return 0;
	}

	LRESULT FigureComboBox::OnNotification(WPARAM wParam, LPARAM lParam)
	{
		MessageBox(parent, L"Got Notification for SongComboBox", L"Error", MB_OK);
		return 0;
	}
}