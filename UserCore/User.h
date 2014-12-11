#pragma once

#include "UserCoreStd.h"

namespace UserCore
{
	class User
	{
	private:
		WCHAR _name[STRLENGTH], _password[STRLENGTH], _favoriteFigure[STRLENGTH], _favoriteSong[STRLENGTH];
	public:
		User();
		User(const WCHAR *name, const WCHAR *password, const WCHAR *favoriteFigure, const WCHAR *favoriteSong);
		~User();
		void SetName(const WCHAR *source);
		void SetPassword(const WCHAR *source);
		void SetFavoriteFigure(const WCHAR *source);
		void SetFavoriteSong(const WCHAR *source);
		const WCHAR* GetName();
		const WCHAR* GetPassword();
		const WCHAR* GetFavoriteFigure();
		const WCHAR* GetFavoriteSong();
		void WriteToFile(FILE *file);
		void ReadFromFile(FILE *file);
	};
}