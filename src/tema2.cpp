/// Tema 2 - verificare

#include <iostream>
#include <fstream>
#include "../include/coin.h"
#include "../include/utility_token.h"
#include "../include/token.h"
#include <memory>


void tema2()
{
    std::cout << "                           == Tema 2 ==  \n\n" ;

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


    ///apelarea constructorului din clasa de baza
    token t2;
    coin *p = new coin;
    p->print();
    delete p;

    ///smart pointers
    std::unique_ptr<coin> p1(new coin("Polkadot","DOT",23200));
    std::unique_ptr<coin> p2;
    p1->print();
    p2 = move(p1);
    p2->print();


    ///dynamic_cast
    utility_token D("GameStop","GMT",1400,"Context Token") ;//("Tether","USDT",122);
    coin& a = D;
    utility_token& new_d = dynamic_cast<utility_token&>(a);
    new_d.print();


    ///suprascris cc/op= pentru copieri/atribuiri corecte, copy and swap
    D.setRol("Exchange Token");
    utility_token D2 = D ;
    D.setRol("Game Token");
    D.print();
    D2.print();

    ///exceptii
    try
    {
        coin y(""); ///Numele nu trebuie sa fie vid
    }
    catch (const char *msg )
    {
        std::cout<<"Eroare: "<<msg<<"\n";
    }

    ///Testare Functionalitati:
    coin btc("Bitcoin","BTC",100);
    try
    {
        float x1 = btc.MA(100);
        std::cout<<"Media ultimelor zile este: "<< x1<<std::endl;
    }
    catch (const char *msg )
    {
        std::cout<<"Eroare: "<<msg<<"\n";
    }

    try
    {
        float x2 = btc.dev(100);
        std::cout<<"Deviatia medie este: "<< x2<<std::endl;
    }
    catch (const char *msg )
    {
        std::cout<<"Eroare: "<<msg<<"\n";
    }

    g.close();


}
