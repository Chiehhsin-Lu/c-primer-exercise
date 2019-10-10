#ifndef BULK_QUOTE_H
#define BULK_QUOTE_H
#include "disc_quote.h"


class Bulk_quote : public Disc_quote
{
public:
    Bulk_quote() = default;
    Bulk_quote(const string &book,double price,size_t qty,double disc) : Disc_quote(book,price,qty,disc) {}

    double net_price(size_t n) const override;
private:
    size_t min_qty = 0;           //适用于折扣政策的最小购买量
    double discount = 0.0;        //折扣额
};

#endif // BULK_QUOTE_H
