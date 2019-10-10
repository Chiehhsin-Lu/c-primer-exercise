#ifndef SCREEN_H
#define SCREEN_H
#include <iostream>
using namespace std;

class Screen
{
    friend class Window_mgr;
public:
    typedef string::size_type pos;
    //使用类型别名等价声明
//    using pos =  string::size_type;
    Screen() = default;
    Screen(pos ht,pos wd,char c):height(ht),width(wd),contents(ht*wd,c) {}
    char get() const
        {return contents[cursor];}            //读取光标处字符，隐式内联
    inline char get(pos ht,pos c) const;      //显式内联
    Screen &move(pos r,pos c);
    void some_memeber() const;

    Screen &set(char);
    Screen &set(pos,pos,char);

    Screen &display(ostream &os)
        {do_display(os);return *this;}
    const Screen &display(ostream &os) const
        {do_display(os);return *this;}
private:
    pos cursor = 0;
    pos height = 0,width = 0;
    string contents;

    mutable size_t access_ctr;

    void do_display(ostream &os) const {os << contents;}
};

#endif // SCREEN_H
