#ifndef COIN_H
#define COIN_H
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
#include "timp.h"
#include "candela.h"
//#include "../src/coin.cpp"

std::vector<std::vector<std::string> > parseCSV(std::string src);

class coin
{
protected:

    std::string name ="";
    std::string ticker;
    int cant = 0;
public:
    coin();
    virtual ~coin();
    coin ( const std::string& name_, const std::string& ticker_, int cant_ ):name (name_), ticker (ticker_), cant(cant_) {}
    coin ( const std::string& name_, const std::string& ticker_) :name (name_), ticker (ticker_){cant = 0; }
    explicit coin ( const std::string& ticker_):ticker (ticker_)
    {
        if (ticker_ == "")
            throw "SIR_VID";
    }
    coin ( const coin& x):name(x.name), ticker (x.ticker), cant(x.cant) {}
    virtual void print();
    std::string getName();
    friend std::ostream& operator << (std::ostream& os, const coin& x);
    friend std::istream& operator >> ( std::istream& is, coin& x);
    coin operator = ( const coin& x);
    coin operator + ( const coin& x);
    coin operator - ( const coin& x);
    coin operator + (int x);
    coin operator - (int x);
    void evolutie ( timp DataInitiala, timp DataFinala);
    void FileConvert();
    int MA(int d);
};

#endif // COIN_H
