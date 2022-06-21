#include "../include/pereche.h"

pereche::pereche()
{
    //ctor
}

pereche::~pereche()
{
    //dtor
}

pereche& pereche::operator = (const pereche &x)
{
    sell_coin = x.sell_coin;
    buy_coin = x.buy_coin;
    return *this;
}

std::ostream& operator << (std::ostream& os, const pereche& x)
{
    os<<"Perechea: \n"<<x.sell_coin<<"\n"<<x.buy_coin;
    return os;
}
