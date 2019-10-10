#include "hasptr.h"

//行为像值的类
//HasPtr& HasPtr::operator =(const HasPtr &rhs){
//    auto newp = new string(*rhs.ps);
//    delete ps;
//    ps = newp;
//    i = rhs.i;
//    return *this;
//}
//行为像指针的类
//HasPtr& HasPtr::operator =(const HasPtr &rhs){
//    ++*rhs.use;
//    if(--*use == 0){
//        delete ps;
//        delete use;
//    }
//    ps = rhs.ps;
//    i = rhs.i;
//    use = rhs.use;
//    return *this;
//}
//在赋值运算符中使用swap
HasPtr& HasPtr::operator =(HasPtr rhs){
    swap(*this,rhs);
    return *this;
}
