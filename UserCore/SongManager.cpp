#pragma once

#include "SongManager.h"

namespace UserCore
{
	SongManager::SongManager()
	{
		_songsCount = 5;
		memset(_songs, 0, STRLENGTH*sizeof(WCHAR)*_songsCount);
		lstrcpynW(_songs[0], L"Numb", STRLENGTH);
		lstrcpynW(_songs[1], L"NewDivide", STRLENGTH);
		lstrcpynW(_songs[2], L"TheCatalyst", STRLENGTH);
		lstrcpynW(_songs[3], L"BleedItOut", STRLENGTH);
		lstrcpynW(_songs[4], L"Rebellion", STRLENGTH);
		WCHAR buffer[MAXSTRING];
		for (int i = 0; i < _songsCount; i++)
		{
			swprintf_s(buffer, MAXSTRING, L"open Songs\\%ws.mp3 type MpegVideo alias %ws", _songs[i], _songs[i]);
			mciSendStringW(buffer, NULL, 0, NULL);
		}
	}

	SongManager::~SongManager()
	{
		WCHAR buffer[STRLENGTH+6];
		for (int i = 0; i < _songsCount; i++)
		{
			swprintf_s(buffer, STRLENGTH+6, L"close %ws", _songs[i]);
			mciSendStringW(buffer, NULL, 0, NULL);
		}
	}

	WCHAR* SongManager::GetSong(int id)
	{
		if (id < _songsCount)
			return _songs[id];
		return NULL;
	}

	int SongManager::GetSongsCount()
	{
		return _songsCount;
	}
}