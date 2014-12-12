#pragma once

#include "User.h"

namespace UserCore
{
	User::User()
	{
	}

	User::User(const WCHAR *name, const WCHAR *password, const WCHAR *favoriteFigure, const WCHAR *favoriteSong)
	{
		SetName(name);
		SetPassword(password);
		SetFavoriteFigure(favoriteFigure);
		SetFavoriteSong(favoriteSong);
	}

	User::~User()
	{
	}

	void User::SetName(const WCHAR *source)
	{
		lstrcpynW(_name, source, STRLENGTH);
		return;
	}

	void User::SetPassword(const WCHAR *source)
	{
		lstrcpynW(_password, source, STRLENGTH);
		return;
	}

	void User::SetFavoriteFigure(const WCHAR *source)
	{
		lstrcpynW(_favoriteFigure, source, STRLENGTH);
		return;
	}

	void User::SetFavoriteSong(const WCHAR *source)
	{
		lstrcpynW(_favoriteSong, source, STRLENGTH);
		return;
	}

	const WCHAR* User::GetName()
	{
		return _name;
	}

	const WCHAR* User::GetPassword()
	{
		return _password;
	}

	const WCHAR* User::GetFavoriteFigure()
	{
		return _favoriteFigure;
	}

	const WCHAR* User::GetFavoriteSong()
	{
		return _favoriteSong;
	}

	void User::WriteToFile(FILE *file)
	{
		fwrite(_name, STRLENGTH*sizeof(WCHAR), 1, file);
		fwrite(_password, STRLENGTH*sizeof(WCHAR), 1, file);
		fwrite(_favoriteFigure, STRLENGTH*sizeof(WCHAR), 1, file);
		fwrite(_favoriteSong, STRLENGTH*sizeof(WCHAR), 1, file);
	}

	void User::ReadFromFile(FILE *file)
	{
		fread(_name, STRLENGTH*sizeof(WCHAR), 1, file);
		fread(_password, STRLENGTH*sizeof(WCHAR), 1, file);
		fread(_favoriteFigure, STRLENGTH*sizeof(WCHAR), 1, file);
		fread(_favoriteSong, STRLENGTH*sizeof(WCHAR), 1, file);
	}
}