/// Tema 1 - verificare

#include <iostream>
#include <fstream>
#include "../include/candela.h"
#include "../include/coin.h"
#include "../include/pereche.h"


void tema1() /// testarea claselor/ metodelor/ operatorilor din tema 1
{
    std::cout << "                           == Tema 1 ==  " ;
    std::cout << std::endl << std::endl;

    /// Clasa candela

    std::fstream f;
    f.open("../date/date.txt",std::fstream::in);
    candela c;
    std::cout<<"Fisierul cu candele:\n";
    while(f>>c)
        std::cout<<c;
    std::cout<<"\n";
    f.close();

    std::cout<<"Exemple de candele: \n";
    candela c1;
    candela c2(timp{"2022-04-13"}, 40123.57,42000,40000,41000,1000000);
    candela c3(timp{"2015-12-20"}, 462.29);
    c1.setOpen(234.34);
    timp t1("2018-02-01");
    c1.setData(t1);
    std::cout<< c1<< c2<< c3;
    std::cout<<"\n";

    /// Clasa coin
    std::fstream g;
    g.open("../date/coins.txt",std::fstream::in);
    coin x;
    std::cout<<"Exemple de monede:\n";
    while(g>>x)
        std::cout<<x<<"\n";
    std::cout<<"\n";
    g.close();

    coin x3("Bitcoin","BTC",13),x4("Bitcoin","BTC",200),x5("Bitcoin","BTC",24000);
    std::cout<<"Adunari si scaderi:\n"<<x3+x4<<"\n"<<x5+89+x4<<"\n";
    std::cout<<"\n";

    /// Clasa pereche
    coin x1("Egold","EGLD",1), x2("FutureCoin", "FUTURE", 150000);
    pereche p1, p2(x1,x2);
    std::cout<<"Exemple de perechi:\n"<<p1<<p2<<std::endl;
    std::cout<<std::endl;

    /// Clasa timp
    timp t3{"2022-04-13"}, t4("2022-04-13");
    std::cout<< t3 << "==" <<t4<<" : " << (t3 == t4)<< std::endl ;

}


void analiza()///Analiza istorica a unei monede
{
    ///1. Schimbati DataInitiala si DataFinala cu cate o valoare in intervalul [2014-09-17, 2022-04-25]
    timp DataInitiala( "2015-02-01" );
    timp DataFinala  ( "2019-03-01" );
    ///2. Rulati programul. Programul va afisa o analiza a pretului monedei in perioada respectiva
    coin btc("Bitcoin","BTC",100);
    std::cout<<"                       == Analiza istoric pret ==\n\n";
    btc.evolutie ( DataInitiala, DataFinala);
    std::cout<<"\n";

    coin eth("Etereum","ETH",250);
    eth.evolutie(timp("2018-01-01"), timp("2022-01-01"));
    std::cout<<"\n";

    coin bnb("Binance Coin","BNB");
    bnb.evolutie(timp{"2018-01-01"},timp{"2022-01-01"});

}
