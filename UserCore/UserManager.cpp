#pragma once

#include "UserManager.h"

namespace UserCore
{
	UserManager::UserManager(int maxUserCount)
	{
		_users = (User*)malloc(maxUserCount*sizeof(User));
		for (int i = 0; i < maxUserCount; i++)
			_users[i] = User();
		_userCount = 0;
	}

	UserManager::~UserManager()
	{
		free(_users);
	}

	void UserManager::AddUser(User user)
	{
		_users[_userCount] = user;
		_userCount++;
		return;
	}

	bool UserManager::GetUser(LPCWSTR name, User &data)
	{
		for (int i = 0; i < _userCount; i++)
			if (!lstrcmpW(name, _users[i].GetName()))
			{
				data = _users[i];
				return true;
			}
		return false;
	}

	void UserManager::ReplaceUser(LPCWSTR name, User user)
	{
		for (int i = 0; i < _userCount; i++)
			if (!lstrcmpW(name, _users[i].GetName()))
			{
				_users[i] = user;
				return;
			}
		return;
	}

	void UserManager::LoadFromFile(char *filename)
	{
		FILE *users;
		if (fopen_s(&users, filename, "rb"))
			throw "Users data file not found";
		int count;
		fread(&count, sizeof(int), 1, users);
		_userCount = count;
		for (int i = 0; i < count; i++)
		{
			_users[i].ReadFromFile(users);
		}
		fclose(users);
		return;
	}

	void UserManager::SaveToFile(char *filename)
	{
		FILE *users;
		if (fopen_s(&users, filename, "wb"))
			throw "Users data file not found";
		fwrite(&_userCount, sizeof(int), 1, users);
		for (int i = 0; i < _userCount; i++)
		{
			_users[i].WriteToFile(users);
		}
		fclose(users);
		return;
	}
}