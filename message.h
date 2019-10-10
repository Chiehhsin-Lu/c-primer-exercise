#ifndef MESSAGE_H
#define MESSAGE_H
#include <iostream>
#include <set>
#include "folder.h"

using namespace std;

class Message
{
    friend class Folder;
    friend void swap(Message&,Message&);
public:
    //folders被隐式初始化为空集合
    explicit Message(const string &str = "") : contents(str) {}
    //拷贝控制函数，管理指向本Message的指针
    Message(const Message&);
    Message& operator=(const Message&);
    ~Message();
    //从给定的Folder集合中添加/删除本Message
    void save(Folder&);
    void remove(Folder&);
private:
    string contents;                       //实际消息文本
    set<Folder*> folders;                  //包含本Message的Folder
    //工具函数，将本Message添加到指向参数的Folder中
    void add_to_Folders(const Message&);
    //工具函数，从folders中的每个folder删除本Message
    void remove_from_Folders();
};
void swap(Message &lhs,Message &rhs){
    using std::swap;
    //将每个消息的指针从原来所在Folder中删除
    for(auto f:lhs.folders){
//        f->remMsg(&lhs);
    }
    for(auto f:rhs.folders){
//        f->remMsg(&rhs);
    }
    //交换contens和Folder指针set
    swap(lhs.folders,rhs.folders);
    swap(lhs.contents,lhs.contents);
    //将每个Message指针添加到新的Folder中
    for(auto f:lhs.folders){
//        f->addMsg(&lhs);
    }
    for(auto f:rhs.folders){
//        f->addMsg(&rhs);
    }
}

#endif // MESSAGE_H
