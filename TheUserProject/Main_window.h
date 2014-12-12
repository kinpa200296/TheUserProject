#pragma once

#include "ProjectStd.h"
#include "SongComboBox.h"
#include "FigureComboBox.h"
#include "Button.h"
#include "StaticText.h"
#include "Edit.h"

namespace TheUserProject
{
	class Main_window : public Window
	{
	public:

		Main_window(HINSTANCE hinst, int nCmdShow, LPCWSTR app_title, LPCWSTR main_class);
		~Main_window();
	//	registers, creates window and adds necessary messages
		void Start();
	//	shows window
	//	should be called after all child windows have been created
		void Show(int nCmdShow);

	//	processes message WM_CLOSE
		LRESULT OnClose(WPARAM, LPARAM);
	//	processes message WM_COMMAND
		LRESULT OnCommand(WPARAM, LPARAM);
		LRESULT OnPaint(WPARAM, LPARAM);

		void HideAllWindows();
		void OnLogin();
		void OnRegister();
		bool VerifyLogin();
		bool VerifyRegister();
		void OnLogout();
		void OnLoggedIn();
		void OnRegistered();
		void OnDrawFigure();
		void OnPlaySong();

	private:

		SongComboBox *_songComboBox;
		FigureComboBox *_figureComboBox;
		Button *_login, *_register, *_logout, *_loginButton, *_registerButton, *_playSong, *_drawFigure;
		StaticText *_welcome, *_loginUsernameText, *_loginPasswordText, *_registerUsernameText, *_registerPasswordText, 
			*_registerPasswordConfirmText, *_songSelectionText, *_figureSelectionText, *_playSongText, *_drawFigureText;
		Edit *_loginUsernameEdit, *_loginPasswordEdit, *_registerUsernameEdit, *_registerPasswordEdit, 
			*_registerPasswordConfirmEdit;
		SongManager *_music;
		UserManager *_userManager;
		User _currentUser;
		bool _paintFigure;
	};
}