#include "../include/coin.h"

coin::coin()
{
    //ctor
    (*this).name = "CoinNesetat";
}

coin::~coin()
{
    //dtor
}

void coin::print()
{
    std::cout<< "Moneda selectata: "<<name<<" are ticker-ul "<<ticker<<" si este detinuta in cantitatea: " <<cant <<"\n";
}

std::string coin::getName()
{
    return name;
}

std::ostream& operator << (std::ostream& os, const coin& x)
{
    os << "Name: "<<x.name<<", ticker: "<<x.ticker<<", cantitate: "<<x.cant ;
    return os;
}
std::istream& operator >> ( std::istream& is, coin& x)
{
    is >> x.name >> x.ticker >> x.cant;
    return is;
}
coin coin::operator = ( const coin& x)
{
    name = x.name;
    ticker = x.ticker;
    cant = x.cant;
    return *this;
}
coin coin::operator + ( const coin& x)
{
    coin a(*this);
    a.cant += x.cant;
    return a;
}
coin coin::operator - ( const coin& x)
{
    coin a(*this);
    a.cant -= x.cant;
    return a;
}
coin coin::operator + (int x)
{
    coin a(*this);
    a.cant += x;
    return a;
}
coin coin::operator - (int x)
{
    coin a(*this);
    a.cant -= x;
    return a;
}
void coin::evolutie ( timp DataInitiala, timp DataFinala)
{
    if ( DataFinala < DataInitiala)
    {
        std::cout<<"Eroare: DataInitiala > DataFinala "<<std::endl;
        return;
    }
    std::cout << "Analizam " << (*this).getName() << " de la data " << DataInitiala << " la data " <<DataFinala << ":\n";

    ///Partea de convertire fisiere
    std::string fisier_api = "date/" + (*this).ticker + "-USD.csv";
    std::string fisier_convertit = "date/" + (*this).ticker + "-USD.txt";
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
