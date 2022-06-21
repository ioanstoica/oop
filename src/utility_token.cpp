#include "../include/utility_token.h"
#include <iostream>

utility_token::utility_token()
{
    //ctor
    (*this).name = "TokenNesetat";
}

utility_token::~utility_token()
{
    //dtor
}

void utility_token::print()
{
    std::cout<< "Utility token: "<<name<<" are ticker-ul "<<ticker<<", cantitate: " <<cant << " folosit ca si: "<<rol<<"\n";
}

utility_token utility_token::operator = ( const utility_token& x)
{
    name = x.name;
    rol = x.rol;
    ticker = x.ticker;
    cant = x.cant;
    return *this;
}

void utility_token::setRol(const std::string rol_)
{
    rol = rol_;
}

void swap(utility_token &a, utility_token &b)
{
    utility_token aux = a;
    a = b;
    b =aux;
}
