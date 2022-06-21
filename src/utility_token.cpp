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

void utility_token::setRol(const std::string &rol_)
{
    rol = rol_;
}
