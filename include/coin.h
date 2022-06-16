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
    coin ( const std::string& name_, const std::string& ticker_) :name (name_), ticker (ticker_)
    {
        cant = 0;
    }
    explicit coin ( const std::string& ticker_):ticker (ticker_){}
    coin ( const coin& x):name(x.name), ticker (x.ticker), cant(x.cant) {}
    void print()
    {
        std::cout<< "Moneda selectata: "<<name<<" are ticker-ul "<<ticker<<" si este detinuta in cantitatea: " <<cant ;
    }
    std::string getName()
    {
        return name;
    }
    friend std::ostream& operator << (std::ostream& os, const coin& x)
    {
        os << "Name: "<<x.name<<", ticker: "<<x.ticker<<", cantitate: "<<x.cant ;
        return os;
    }
    friend std::istream& operator >> ( std::istream& is, coin& x)
    {
        is >> x.name >> x.ticker >> x.cant;
        return is;
    }
    coin operator = ( const coin& x)
    {
        name = x.name;
        ticker = x.ticker;
        cant = x.cant;
        return *this;
    }
    coin operator + ( const coin& x)
    {
        coin a(*this);
        a.cant += x.cant;
        return a;
    }
    coin operator - ( const coin& x)
    {
        coin a(*this);
        a.cant -= x.cant;
        return a;
    }
    coin operator + (int x)
    {
        coin a(*this);
        a.cant += x;
        return a;
    }
    coin operator - (int x)
    {
        coin a(*this);
        a.cant -= x;
        return a;
    }
    void evolutie ( timp DataInitiala, timp DataFinala)
    {
        if ( DataFinala < DataInitiala)
        {
            std::cout<<"Eroare: DataInitiala > DataFinala "<<std::endl;
            return;
        }
        std::cout << "Analizam " << (*this).getName() << " de la data " << DataInitiala << " la data " <<DataFinala << ":\n";

        ///Partea de convertire fisiere
        std::string fisier_api = (*this).ticker + "-USD.csv";
        std::string fisier_convertit = (*this).ticker + "-USD.txt";
        std::ofstream g(fisier_convertit);
        std::vector<std::vector<std::string> > parsedCSV;
        parsedCSV = parseCSV(fisier_api); /// (dest, src)
        auto i = parsedCSV.begin() ;
        ++i;

        for( ; i != parsedCSV.end(); ++i)
        {
            int k = 0;
            for (auto j = (*i).begin(); j!= (*i).end(); ++k,++j)
                if ( k!=5 )
                    g << (*j) << " " ;
            g<<std::endl;
        }

        g.close();

        std::fstream f;
        f.open(fisier_convertit,std::fstream::in);


        candela c;
        double PretInitial = -1, PretFinal = -1;
        while(f>>c)
        {
            timp Data = c.getData();
            if (Data == DataInitiala )
                PretInitial = c.getOpen();
            if (Data == DataFinala)
                PretFinal = c.getOpen();
        }

        if (PretInitial == -1 || PretFinal == -1)
        {
            std::cout<<"Nu am gasit DataInitiala sau DataFinala"<<std::endl;
            return ;
        }

        std::cout<<"Pretul la data de " << DataInitiala << " era " << PretInitial<<"$ iar la data de " <<DataFinala << " era " << PretFinal<< "$."<< std::endl;
        double modificarePret = (PretFinal - PretInitial) / PretInitial;
        if (modificarePret >= 0)
            std::cout << "Pretul a crescut cu " << modificarePret *100 <<"%\n";
        else
            std::cout << "Pretul a scazut cu " << modificarePret *100 <<"%\n";

        double NrAni = double(DataFinala.getAn() - DataInitiala.getAn()) ;
        if (NrAni > 1 ) /// PretInitial * (1+ModificareaAnuala)^NrAni = PretFinal => (1+ModificareaAnuala)^NrAni = PretFinal/PretInitial => 1+ModificareaAnuala = (PretFinal/PretInitial)^(1/NrAni) => ModificareaAnuala = (PretFinal/PretInitial)^(1/NrAni) -1
        {
            double ModificareaAnuala = pow(PretFinal/PretInitial,1/NrAni) -1 ;
            std::cout<<"In cei " << NrAni <<" ani "<< "modificarea medie anuala a pretului a fost de " << ModificareaAnuala * 100 <<"%\n" ;
        }


        f.close();
        return;
    }
};

#endif // COIN_H
