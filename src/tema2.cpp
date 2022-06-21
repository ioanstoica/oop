/// Tema 2 - verificare

#include <iostream>
#include <fstream>
#include "../include/coin.h"



void tema2()
{
    std::fstream g;
    g.open("date/coins.txt",std::fstream::in);
    coin x;
    g>>x;
    x.print();
    std::cout<<"\n";
    std::cout<<x;
    g.close();
}
