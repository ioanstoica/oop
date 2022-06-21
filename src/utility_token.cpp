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
    std::cout<< "Utility token: "<<name<<" are ticker-ul "<<ticker<<" si este detinuta in cantitatea: " <<cant <<"\n";
}
