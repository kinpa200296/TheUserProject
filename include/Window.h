#pragma once

#include "std.h"

namespace WinAPIWrap
{
	//
	//	Class: Window
	//	
	//	Base class for other classes that handle operations with windows
	//				
	class Window
	{
	public:
	//	pointer to event handler function
		typedef LRESULT (Window::*funcpointer)(WPARAM, LPARAM);
	//	holds pointers to current window object and event handler function
		struct POINTER
		{
	//		a pointer to current window object
			Window *wnd;
	//		pointer to event handler function
			funcpointer function;
		};
	//	holds POINTER struct for every type of Windows message required
		typedef map<UINT, POINTER> message_map;

	//	curent window handle
		HWND window;
	//	parent window handle
		HWND parent;
	//	current application instance
		HINSTANCE app_inst;
	//	coordinates of the window on the screen
		int x, y, width, height;
	//	Window style
		DWORD ExStyle, Style;
	//	window Id, when window is child
	//	used by Windows to tell parent window which child window needs to proceed
		HMENU hMenu;
		WCHAR window_title[MAXSTRING], class_name[MAXSTRING];

	//	holds unique message maps for each window handles in the application
		static map<HWND, message_map> global_message_map;

	// 
	//	Registers window class
	//	do not call when using standard controls
	//
		virtual ATOM RegisterWindowClass(UINT window_style, HBRUSH Background_brush, HINSTANCE Icon_inst = NULL, 
									 LPCWSTR Icon_name = NULL, HINSTANCE IconSm_inst = NULL, LPCWSTR IconSm_name = NULL,
									 LPCWSTR Menu_name = NULL, HINSTANCE Cursor_inst = NULL, LPCWSTR Cursor_name = MAKEINTRESOURCEW(IDC_ARROW));
	//
	//	Adds message which should be handled to global_message_map
	//
		static bool AddMessage(HWND _hwnd, UINT message, Window *wnd, funcpointer func);

	//
	//	initializes window parametrs
	//
		Window(HINSTANCE hinst, HWND _parent, int _x, int _y, int _width, int _height, LPCWSTR title, LPCWSTR ClassName,
				DWORD _ExStyle, DWORD _Style, HMENU _hMenu = NULL);
		~Window();
	//
	//	Function: bool create()
	//		creates window without showing it
	//	RETURN:
	//		true if window created
	//		false otherwise
	//
		bool create();
	//
	//	basic window procedure
	//	checks if message is in global_message_map
	//	if it is there then event handler is called
	//	otherwise DefWndProc function will be called
	//	can be used to interrupt messages
	//
		static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

	private:

	};

	//
	//	Mañro: To_funcpointer(function_ptr)
	//
	//	Purpose: Transforms function pointer to Window::funcpointer
	//
	#define To_funcpointer(function_ptr) reinterpret_cast<funcpointer>(function_ptr)
}