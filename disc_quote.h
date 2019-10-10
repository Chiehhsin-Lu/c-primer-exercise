#ifndef DISC_QUOTE_H
#define DISC_QUOTE_H
#include "quote.h"
using namespace std;

class Disc_quote : public Quote
{
public:
    Disc_quote() = default;
    Disc_quote(const string &book,double price,size_t qty,double disc) : Quote(book,price),quantity(qty),discount(disc) {}

    double net_price(size_t n) const = 0;
protected:
    size_t quantity = 0;             //折扣适用的购买量
    double discount = 0.0;           //表示折扣的数值
};

#endif // DISC_QUOTE_H
