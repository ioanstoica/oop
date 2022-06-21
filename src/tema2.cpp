/// Tema 2 - verificare

#include <iostream>
#include <fstream>
#include "../include/coin.h"
#include "../include/utility_token.h"
#include "../include/token.h"


void tema2()
{
    /// mosteniri
    std::fstream g;
    g.open("date/coins.txt",std::fstream::in);
    ///     functii virtuale (pure), constructori virtuali (clone)
    ///     functiile virtuale vor fi apelate prin pointeri la clasa de baza
    token t;
    utility_token x;

    g>>x;
    t.setP(&x);
    t.print();
    std::cout<<"\n";

    ///



    g.close();


}
