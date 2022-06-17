/// Tema 2 - verificare

#include <iostream>
#include <fstream>
#include "../include/coin.h"



void tema2()
{
    std::fstream g;
    g.open("coins.txt",std::fstream::in);
    coin x;
    g>>x;
    std::cout<<x;
    g.close();
}
