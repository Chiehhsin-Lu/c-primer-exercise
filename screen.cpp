#include "screen.h"

inline Screen &Screen::move(pos r,pos c){
    pos row = r*width;         //计算行的位置
    cursor = row + c;          //在行内将光标移动到指定列
    return *this;
}

char Screen::get(pos r,pos c) const{
    pos row = r*width;
    return contents[row+c];
}

void Screen::some_memeber() const{
    ++access_ctr;
}

inline Screen &Screen::set(char c){
    contents[cursor] = c;
    return *this;
}

inline Screen &Screen::set(pos r,pos col,char ch){
    contents[r*width+col] = ch;
    return *this;
}
