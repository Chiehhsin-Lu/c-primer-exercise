#ifndef HASPTR_H
#define HASPTR_H
#include <iostream>
using namespace std;

class HasPtr
{
    friend void swap(HasPtr&,HasPtr&);
public:
//    HasPtr(const string &s =string()) : ps(new string(s)),i(0) {}
//    //行为像值的类
//    HasPtr(const HasPtr &p) : ps(new string(*p.ps)),i(p.i) {}
//    HasPtr& operator=(const HasPtr &);
//    ~HasPtr() {delete ps;}
    //行为像指针的类
    HasPtr(const string &s = string()):ps(new string(s)),i(0),use(new size_t(1)) {}
    HasPtr(const HasPtr &p):ps(p.ps),i(p.i),use(p.use) {++*use;}
//    HasPtr& operator=(const HasPtr&);
    ~HasPtr(){
        if(--*use == 0){
            delete ps;
            delete use;
        }
    }
    //在赋值运算符中使用swap
    HasPtr& operator=(HasPtr);
private:
    string *ps;
    int i;
    size_t *use;                         //记录多少个对象共享*ps的成员
};
inline void swap(HasPtr &lhs,HasPtr &rhs){
    using std::swap;
    swap(lhs.ps,rhs.ps);
    swap(lhs.i,rhs.i);
}

#endif // HASPTR_H
