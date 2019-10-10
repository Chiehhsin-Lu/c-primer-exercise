#ifndef SALES_DATA_H
#define SALES_DATA_H
#include <iostream>

using namespace std;

class Sales_data
{
    //非成员接口的友元声明
    friend Sales_data add(const Sales_data&,const Sales_data&);
    friend ostream &print(ostream&,const Sales_data&);
    friend istream &read(istream&,Sales_data&);
    //重载输入输出运算符
    friend ostream &operator<<(ostream &os,const Sales_data &item);
    friend istream &operator<<(istream &is,Sales_data &item);

    friend bool operator ==(const Sales_data &lhs,const Sales_data &rhs);
    friend bool operator !=(const Sales_data &lhs,const Sales_data &rhs);
public:
    //构造函数
    Sales_data() = default;
    Sales_data(const string &s):bookNo(s) {}
    Sales_data(const string &s,unsigned n,double p):bookNo(s),units_sold(n),revenue(p*n) {}
    Sales_data(istream &);
    //拷贝构造函数
    Sales_data(const Sales_data&);
    //拷贝赋值运算符
    Sales_data& operator=(const Sales_data&);
    //析构函数
    ~Sales_data() {}

    string isbn() const {return bookNo;}  //const作用，修改隐式this指针的类型
    Sales_data& combine(const Sales_data&);

private:
    double avg_price() const
        {return units_sold?revenue/units_sold:0;}

    string bookNo;                       //ISBN号
    unsigned units_sold = 0;             //销售数量
    double revenue = 0.0;                //销售收入
};

//非成员接口
Sales_data add(const Sales_data&,const Sales_data&);
ostream &print(ostream&,const Sales_data&);
istream &read(istream&,Sales_data&);
//重载输出运算符
ostream &operator<<(ostream &os,const Sales_data &item){
    os << item.isbn() << " " << item.units_sold << " "
       << item.revenue << " " << item.avg_price();
    return os;
}
istream &operator<<(istream &is,Sales_data &item){
    double price;
    is >> item.bookNo >> item.units_sold >> price;
    if(is)
        item.revenue = item.units_sold*price;
    else
        item = Sales_data();
    return is;
}

//Sales_data operator+(Sales_data &lhs,Sales_data &rhs){
//    Sales_data sum = lhs;
//    sum += rhs;
//    return sum;
//}未定义+=运算符
bool operator ==(const Sales_data &lhs,const Sales_data &rhs){
    return lhs.isbn()==rhs.isbn() &&
            lhs.units_sold==rhs.units_sold &&
            lhs.revenue==rhs.revenue;
}
bool operator !=(const Sales_data &lhs,const Sales_data &rhs){
    return !(lhs==rhs);
}

#endif // SALES_DATA_H
