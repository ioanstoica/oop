#include "../include/token.h"

token::token()
{
    //ctor
}

token::~token()
{
    //dtor
}

void token::setP(coin *p_)
{
    p = p_;
}

void token::print()
{
    p->print();
}
