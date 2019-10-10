#ifndef QUOTE_H
#define QUOTE_H
#include <iostream>
using namespace std;

class Quote
{
public:
    Quote() = default;
    Quote(const string &book,double sales_price) : bookNo(book),price(sales_price) {}

    string isbn() const {return bookNo;}
    virtual double net_price(size_t n) const
        {return n*price;}
    virtual ~Quote() = default;            //对析构函数动态绑定
private:
    string bookNo;
protected:
    double price = 0.0;
};

#endif // QUOTE_H
