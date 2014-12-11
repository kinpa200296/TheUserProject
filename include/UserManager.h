#pragma once

#include "User.h"

namespace UserCore
{
class UserManager
{
	private:
		User *_users;
		int _userCount;
	public:
		UserManager(int maxUserCount);
		~UserManager();
		void AddUser(User user);
		bool GetUser(LPCWSTR name, User &data);
		void ReplaceUser(LPCWSTR name, User user);
		void LoadFromFile(char *filename);
		void SaveToFile(char *filename);
	};
}