#pragma once

#include "resource.h"

#include "std.h"
#include "Window.h"
#include "UserCoreStd.h"
#include "User.h"
#include "UserManager.h"
#include "SongManager.h"

#define MAX_USER_COUNT 1000
#define MIN_PASSWORD_LENGTH 4

#define ID_LOGIN 8801
#define ID_REGISTER 8802
#define ID_LOGOUT 8803
#define ID_WELCOME 8804
#define ID_LOGIN_USERNAME_STATIC 8805
#define ID_LOGIN_PASSWORD_STATIC 8806
#define ID_LOGIN_BUTTON 8807
#define ID_LOGIN_USERNAME_EDIT 8808
#define ID_LOGIN_PASSWORD_EDIT 8809
#define ID_REGISTER_BUTTON 8810
#define ID_REGISTER_USERNAME_STATIC 8811
#define ID_REGISTER_PASSWORD_STATIC 8812
#define ID_REGISTER_PASSWORD_CONFIRM_STATIC 8813
#define ID_REGISTER_USERNAME_EDIT 8814
#define ID_REGISTER_PASSWORD_EDIT 8815
#define ID_REGISTER_PASSWORD_CONFIRM_EDIT 8816
#define ID_SONG_COMBOBOX 8817
#define ID_FIGURE_COMBOBOX 8818
#define ID_SONG_SELECTION_STATIC 8819
#define ID_FIGURE_SELECTION_STATIC 8820
#define ID_SONG_STATIC 8821
#define ID_FIGURE_STATIC 8822
#define ID_PLAY_SONG 8823
#define ID_DRAW_FIGURE 8824

using namespace std;
using namespace WinAPIWrap;
using namespace UserCore;