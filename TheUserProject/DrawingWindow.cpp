#pragma once

#include "DrawingWindow.h"

namespace TheUserProject
{
	DrawingWindow::DrawingWindow(HINSTANCE hinst, HWND parent, int _x, int _y, int _width, int _height, User user) : 
		Window(hinst, parent, _x, _y, _width, _height, L"", L"DrawingWindow", NULL, WS_CHILD | WS_VISIBLE | WS_POPUP)
	{
		_user = user;
	}

	DrawingWindow::~DrawingWindow()
	{
		DestroyWindow(window);
	}

	void DrawingWindow::Start()
	{
		RegisterWindowClass(CS_VREDRAW | CS_HREDRAW, (HBRUSH)(COLOR_WINDOW+1), app_inst, MAKEINTRESOURCEW(IDI_MAIN), 
					app_inst, MAKEINTRESOURCEW(IDI_MAIN));
		create();

		AddMessage(window, WM_PAINT, this, To_funcpointer(&DrawingWindow::OnPaint));
	}

	LRESULT DrawingWindow::OnPaint(WPARAM wParam, LPARAM lParam)
	{
		PAINTSTRUCT ps;
		BeginPaint(window, &ps);
		if (!lstrcmpW(_user.GetFavoriteFigure(), L"Square"))
		{
			SelectObject(ps.hdc, GetStockObject(DC_PEN));
			SetDCPenColor(ps.hdc, RGB(255, 255, 255));
			LineTo(ps.hdc, 10, 10);
			SetDCPenColor(ps.hdc, RGB(255, 0, 0));
			LineTo(ps.hdc, 10, 90);
			LineTo(ps.hdc, 90, 90);
			LineTo(ps.hdc, 90, 10);
			LineTo(ps.hdc, 10, 10);
		}
		if (!lstrcmpW(_user.GetFavoriteFigure(), L"Circle"))
		{
			SelectObject(ps.hdc, GetStockObject(DC_PEN));
			SetDCPenColor(ps.hdc, RGB(255, 255, 255));
			LineTo(ps.hdc, 10, 50);
			SetDCPenColor(ps.hdc, RGB(0, 255, 0));
			for (int i = 10; i <= 90; i++)
				LineTo(ps.hdc, i, 50-(int)sqrt(1600 - (i - 50)*(i - 50)));
			for (int i = 90; i >= 10; i--)
				LineTo(ps.hdc, i, 50+(int)sqrt(1600 - (i - 50)*(i - 50)));
		}
		if (!lstrcmpW(_user.GetFavoriteFigure(), L"Triangle"))
		{
			SelectObject(ps.hdc, GetStockObject(DC_PEN));
			SetDCPenColor(ps.hdc, RGB(255, 255, 255));
			LineTo(ps.hdc, 50, 10);
			SetDCPenColor(ps.hdc, RGB(0, 0, 255));
			LineTo(ps.hdc, 10, 90);
			LineTo(ps.hdc, 90, 90);
			LineTo(ps.hdc, 50, 10);
		}
		EndPaint(window, &ps);
		return 0;
	}
}