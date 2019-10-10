#include "bulk_quote.h"

double Bulk_quote::net_price(size_t cnt) const{
    return cnt>=min_qty?cnt*(1-discount)*price:cnt*price;
}
