﻿#ifndef _MY_WINDOWMGR_H_
#define _MY_WINDOWMGR_H_
#include <vector>
#include "my_Screen.h"

using namespace std;
//class Screen;
class Window_mgr
{
	Window_mgr()
	{
		screens.push_back(Screen(3, 10, 'a'));
	}
	Window_mgr(char a)
	{
		screens{Screen(3, 10, a)};
	}
public:
	typedef vector<Screen>::size_type ScreenIndex;
	void clear(ScreenIndex);
	unsigned char addScreen(const Screen&);
private:
	vector<Screen> screens;
};
void Window_mgr::clear(ScreenIndex i)
{
	Screen &s = screens[i];
	s.content = string(s.height*s.width, ' ');
}

unsigned char Window_mgr::addScreen(const Screen &s)
{
	screens.push_back(s);
	return screens.size()-1;
}

#endif