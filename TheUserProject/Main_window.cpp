#pragma once

#include "Main_window.h"

namespace TheUserProject
{
	Main_window::Main_window(HINSTANCE hinst, int nCmdShow, LPCWSTR app_title, LPCWSTR main_class) : 
		Window(hinst, NULL, 0, 0, 640, 480, app_title, main_class, WS_EX_CLIENTEDGE,
			(WS_OVERLAPPEDWINDOW ^ WS_MAXIMIZEBOX ^ WS_THICKFRAME) | WS_VISIBLE | WS_CLIPCHILDREN | WS_CLIPSIBLINGS )
	{
		_userManager = new UserManager(MAX_USER_COUNT);
	}

	Main_window::~Main_window()
	{
		_userManager->~UserManager();
		_songComboBox->~SongComboBox();
		_figureComboBox->~FigureComboBox();
		_login->~Button();
		_loginButton->~Button();
		_logout->~Button();
		_register->~Button();
		_register->~Button();
		_welcome->~StaticText();
		_loginPasswordEdit->~Edit();
		_loginPasswordText->~StaticText();
		_loginUsernameEdit->~Edit();
		_loginUsernameText->~StaticText();
		_registerPasswordConfirmEdit->~Edit();
		_registerPasswordConfirmText->~StaticText();
		_registerPasswordEdit->~Edit();
		_registerPasswordText->~StaticText();
		_registerUsernameEdit->~Edit();
		_registerUsernameText->~StaticText();
		_songSelectionText->~StaticText();
		_figureSelectionText->~StaticText();
		_playSong->~Button();
		_playSongText->~StaticText();
		_drawFigure->~Button();
		_drawFigureText->~StaticText();
	}

	void Main_window::Start()
	{
		RegisterWindowClass(CS_VREDRAW | CS_HREDRAW, (HBRUSH)(COLOR_WINDOW), app_inst, MAKEINTRESOURCEW(IDI_MAIN), 
					app_inst, MAKEINTRESOURCEW(IDI_MAIN));
		create();

		_login = new Button(app_inst, window, 545, 5, 70, 30, ID_LOGIN, L"Log In");
		_loginButton = new Button(app_inst, window, 265, 270, 70, 30, ID_LOGIN_BUTTON, L"Log In");
		_logout = new Button(app_inst, window, 545, 5, 70, 30, ID_LOGOUT, L"Log Out");
		_register = new Button(app_inst, window, 470, 5, 70, 30, ID_REGISTER, L"Register");
		_registerButton = new Button(app_inst, window, 265, 370, 70, 30, ID_REGISTER_BUTTON, L"Register");
		_welcome = new StaticText(app_inst, window, 10, 10, 300, 20, ID_WELCOME, L"Welcome, Guest. Please Log in or Register.", SS_LEFT);
		_loginUsernameText = new StaticText(app_inst, window, 0, 150, 200, 20, ID_LOGIN_USERNAME_STATIC, L"Username:", SS_RIGHT);
		_loginPasswordText = new StaticText(app_inst, window, 0, 200, 200, 20, ID_LOGIN_PASSWORD_STATIC, L"Password:", SS_RIGHT);
		_loginUsernameEdit = new Edit(app_inst, window, 205, 150, 250, 20, ID_LOGIN_USERNAME_EDIT);
		_loginPasswordEdit = new Edit(app_inst, window, 205, 200, 250, 20, ID_LOGIN_PASSWORD_EDIT, ES_PASSWORD);
		_registerUsernameEdit = new Edit(app_inst, window, 205, 100, 250, 20, ID_REGISTER_USERNAME_EDIT);
		_registerUsernameText = new StaticText(app_inst, window, 0, 100, 200, 20, ID_REGISTER_USERNAME_STATIC, L"Username:", SS_RIGHT);
		_registerPasswordEdit = new Edit(app_inst, window, 205, 150, 250, 20, ID_REGISTER_PASSWORD_EDIT, ES_PASSWORD);
		_registerPasswordText = new StaticText(app_inst, window, 0, 150, 200, 20, ID_REGISTER_PASSWORD_STATIC, L"Password:", SS_RIGHT);
		_registerPasswordConfirmEdit = new Edit(app_inst, window, 205, 200, 250, 20, ID_REGISTER_PASSWORD_CONFIRM_EDIT, ES_PASSWORD);
		_registerPasswordConfirmText = new StaticText(app_inst, window, 0, 200, 200, 20, ID_REGISTER_PASSWORD_CONFIRM_STATIC, L"Confirm Password:", SS_RIGHT);
		_songSelectionText  = new StaticText(app_inst, window, 0, 250, 200, 20, ID_SONG_SELECTION_STATIC, L"Select favorite song:", SS_RIGHT);
		_figureSelectionText = new StaticText(app_inst, window, 0, 300, 200, 20, ID_FIGURE_SELECTION_STATIC, L"Select favorite figure:", SS_RIGHT);
		_songComboBox = new SongComboBox(app_inst, window, 205, 250, 250, 200, ID_SONG_COMBOBOX);
		_figureComboBox = new FigureComboBox(app_inst, window, 205, 300, 250, 200, ID_FIGURE_COMBOBOX);
		_playSong = new Button(app_inst, window, 225, 200, 150, 30, ID_PLAY_SONG, L"Yes, please");
		_playSongText = new StaticText(app_inst, window , 20, 150, 580, 20, ID_SONG_STATIC, L"Do you want me to play your favorite song?", SS_CENTER);
		_drawFigure = new Button(app_inst, window, 225, 300, 150, 30, ID_DRAW_FIGURE, L"Yes, I do");
		_drawFigureText = new StaticText(app_inst, window , 20, 250, 580, 20, ID_FIGURE_STATIC, L"Do you want me to draw your favorite figure?", SS_CENTER);
		
		_login->Start();
		_loginButton->Start();
		_logout->Start();
		_register->Start();
		_registerButton->Start();
		_welcome->Start();
		_loginPasswordEdit->Start();
		_loginPasswordText->Start();
		_loginUsernameEdit->Start();
		_loginUsernameText->Start();
		_registerPasswordConfirmEdit->Start();
		_registerPasswordConfirmText->Start();
		_registerPasswordEdit->Start();
		_registerPasswordText->Start();
		_registerUsernameEdit->Start();
		_registerUsernameText->Start();
		_songSelectionText->Start();
		_figureSelectionText->Start();
		_songComboBox->Start();
		_figureComboBox->Start();
		_playSong->Start();
		_playSongText->Start();
		_drawFigure->Start();
		_drawFigureText->Start();

		HideAllWindows();

		_songComboBox->Fill(_music);
		_figureComboBox->Fill();

		AddMessage(window, WM_CLOSE, this, To_funcpointer(&Main_window::OnClose));
		AddMessage(window, WM_COMMAND, this, To_funcpointer(&Main_window::OnCommand));
	}

	void Main_window::Show(int nCmdShow)
	{
		ShowWindow(window, nCmdShow);
	}

	LRESULT Main_window::OnClose(WPARAM wParam, LPARAM lParam)
	{
		PostQuitMessage(0);
		return 0;
	}

	LRESULT Main_window::OnCommand(WPARAM wParam, LPARAM lParam)
	{
		int wmId = LOWORD(wParam), wmEvent = HIWORD(wParam);
		switch (wmId)
		{
		case ID_EXIT:
			return OnClose(wParam, lParam);
		default:
			break;
		}
		return 0;
	}

	void Main_window::HideAllWindows()
	{
		ShowWindow(_logout->window, SW_HIDE);
		ShowWindow(_loginButton->window, SW_HIDE);
		ShowWindow(_loginPasswordEdit->window, SW_HIDE);
		ShowWindow(_loginPasswordText->window, SW_HIDE);
		ShowWindow(_loginUsernameEdit->window, SW_HIDE);
		ShowWindow(_loginUsernameText->window, SW_HIDE);
		ShowWindow(_registerButton->window, SW_HIDE);
		ShowWindow(_registerPasswordConfirmEdit->window, SW_HIDE);
		ShowWindow(_registerPasswordConfirmText->window, SW_HIDE);
		ShowWindow(_registerPasswordEdit->window, SW_HIDE);
		ShowWindow(_registerPasswordText->window, SW_HIDE);
		ShowWindow(_registerUsernameEdit->window, SW_HIDE);
		ShowWindow(_registerUsernameText->window, SW_HIDE);
		ShowWindow(_songSelectionText->window, SW_HIDE);
		ShowWindow(_figureSelectionText->window, SW_HIDE);
		ShowWindow(_songComboBox->window, SW_HIDE);
		ShowWindow(_figureComboBox->window, SW_HIDE);
		ShowWindow(_playSong->window, SW_HIDE);
		ShowWindow(_playSongText->window, SW_HIDE);
		ShowWindow(_drawFigure->window, SW_HIDE);
		ShowWindow(_drawFigureText->window, SW_HIDE);
	}
}