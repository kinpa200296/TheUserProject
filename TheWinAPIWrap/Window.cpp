#include "Window.h"

using namespace WinAPIWrap;

namespace WinAPIWrap
{
	map<HWND, Window::message_map> Window::global_message_map;

	Window::Window(HINSTANCE hinst, HWND _parent, int _x, int _y, int _width, int _height, LPCWSTR title, LPCWSTR ClassName,
						DWORD _ExStyle, DWORD _Style, HMENU _hMenu)
	{
		app_inst = hinst;
		parent = _parent;
		window = NULL;
		x = _x;
		y = _y;
		width = _width;
		height = _height;
		lstrcpynW(window_title, title, MAXSTRING);
		lstrcpynW(class_name, ClassName, MAXSTRING);
		ExStyle = _ExStyle;
		Style = _Style;
		hMenu = _hMenu;
	}

	Window::~Window()
	{
		DestroyWindow(window);
	}

	ATOM Window::RegisterWindowClass(UINT window_style, HBRUSH Background_brush, HINSTANCE Icon_inst, 
									 LPCWSTR Icon_name, HINSTANCE IconSm_inst, LPCWSTR IconSm_name,
									 LPCWSTR Menu_name, HINSTANCE Cursor_inst, LPCWSTR Cursor_name)
	{
		WNDCLASSEX wndclass;

		memset(&wndclass, 0, sizeof(WNDCLASSEX));

		wndclass.cbSize = sizeof(WNDCLASSEX);
		wndclass.lpszClassName = class_name;
		wndclass.lpfnWndProc = WndProc;
		wndclass.hInstance = app_inst;
		wndclass.style = window_style;
		wndclass.hbrBackground = Background_brush;
		wndclass.hIcon = LoadIcon(Icon_inst, Icon_name);
		wndclass.hIconSm = LoadIcon(IconSm_inst, IconSm_name);
		wndclass.hCursor = LoadCursor(Cursor_inst, Cursor_name);
		wndclass.lpszMenuName = Menu_name;

		return RegisterClassEx(&wndclass);
	};

	bool Window::create()
	{
		window = CreateWindowEx(ExStyle, class_name, window_title, Style, x, y, width, height, parent, hMenu, app_inst, NULL);

		if (!window)
			return false;

		return true;
	}

	bool Window::AddMessage(HWND _hwnd, UINT message, Window *wnd, funcpointer func)
	{
		if (!wnd || !func)
			return false;

		POINTER msg;
		message_map msgmap;
		msg.wnd = wnd;
		msg.function = func;

		map<HWND, message_map>::iterator it = global_message_map.find(_hwnd);

		if (it == global_message_map.end())
		{
			msgmap.clear();
			msgmap.insert(pair<UINT,POINTER>(message, msg));
			global_message_map.insert(pair<HWND, message_map>(_hwnd, msgmap));
		}
		else 
		{
			it->second.insert(pair<UINT, POINTER>(message, msg));
		}

		return true;
	}

	LRESULT CALLBACK Window::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
	{
		POINTER msg;
		message_map msgmap;

		map<HWND, message_map>::iterator it_global = global_message_map.find(hWnd);

		if (it_global == global_message_map.end())
			return DefWindowProc(hWnd, message, wParam, lParam);

		msgmap = it_global->second;

		message_map::iterator it = msgmap.find(message);

		if (it == msgmap.end())
			return DefWindowProc(hWnd, message, wParam, lParam);

		msg = it->second;
		return (msg.wnd->*msg.function)(wParam, lParam);
	}
}