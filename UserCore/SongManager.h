#pragma once

#include "UserCoreStd.h"

namespace UserCore
{
	class SongManager
	{
	private:
		WCHAR _songs[20][STRLENGTH];
		int _songsCount;
	public:
		SongManager();
		~SongManager();
		WCHAR* GetSong(int id);
		int GetSongsCount();
	};
}