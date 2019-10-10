#ifndef WINDOW_MGR_H
#define WINDOW_MGR_H
#include <iostream>
#include <vector>
#include "screen.h"

using namespace std;
class Window_mgr
{
public:
    Window_mgr();
    //窗口中每个屏幕的编号
    using ScreenIndex = vector<Screen>::size_type;
    //按照编号将指定的Screen重置为空白
    void clear(ScreenIndex);
    ScreenIndex addScreen(const Screen&);
private:
    vector<Screen> screens{Screen(24,80,' ')};
};

#endif // WINDOW_MGR_H
