///Tema 2
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <math.h>
#include <ctime>
#include <vector>
#include <sstream>
#include <list>
//#include <conio.h>

using namespace std::literals;

class timp
{
private:
    int an = 0;
    int luna = 0;
    int zi = 0;
public:
    timp () {}
    timp (int an_, int luna_, int zi_) :an(an_), luna(luna_), zi(zi_) {}
    timp (const timp &t): an(t.an), luna(t.luna), zi(t.zi) {}
    explicit timp (const char *s)
    {
        char s_aux[11];
        for(int i=0;i<=10;i++)
            s_aux[i] = s[i];
        s_aux[4]=s_aux[7]=0;
        an = atoi(s_aux);
        luna = atoi(s_aux+5);
        zi = atoi(s_aux+8);
    }
    ~timp () {}
    int getAn ()
    {
        return an;
    }



    friend std::ostream& operator << (std::ostream& os, const timp& t)
    {
        char aux_luna[2]="",aux_zi[3]="";
        if(t.luna<=9)
        {
            aux_luna[0]='0';
            aux_luna[1]=0;
        }
        if(t.zi<=9)
        {
            aux_zi[0]='0';
            aux_zi[1]=0;
        }
        os<<t.an<<"-"<<aux_luna<<t.luna<<"-"<<aux_zi<<t.zi;
        return os;
    }
    friend std::istream& operator >> (std::istream& is, timp& t)
    {
        char m,s,z,u,z2,u2,z3,u3,sep;
        is>>m>>s>>z>>u>>sep>>z2>>u2>>sep>>z3>>u3;
        t.an = 1000*(m-'0')+100*(s-'0')+10*(z-'0')+u-'0';
        t.luna = 10*(z2-'0')+u2-'0';
        t.zi = 10*(z3-'0')+u3-'0';
        return is;
    }
    bool operator < (const timp &t)const
    {
        if((*this).an != t.an)
            return (*this).an < t.an;
        if((*this).luna != t.luna)
            return (*this).luna < t.luna;
        return (*this).zi < t.zi;
    }
    bool operator > (const timp &t)const
    {
        if((*this).an != t.an)
            return (*this).an > t.an;
        if((*this).luna != t.luna)
            return (*this).luna > t.luna;
        return (*this).zi > t.zi;
    }
    timp &operator = (const timp &t)
    {
        (*this).an = t.an;
        (*this).luna = t.luna;
        (*this).zi = t.zi;
        return (*this);
    }
    bool operator == (const timp &t)const
    {
        return !((*this) < t ) && !( (*this) > t );
    }
    bool operator <= (const timp &t)const
    {
        return (*this) < t || (*this) == t ;
    }
    bool operator >= (const timp &t)const
    {
        return (*this) > t || (*this) == t ;
    }

};
class candela
{
private:
    timp Data{"0000-00-00"}; ///format "yyyy-mm-dd"
    double Open = 0, High = 0,Low = 0, Close = 0, Volume = 0;
public:
    candela() {}
    double getOpen()const
    {
        return Open;
    }
    timp getData()
    {
        return Data;
    }
    void setOpen(double Open_)
    {
        Open = Open_;
    }
    void setData(timp Data_)
    {
        Data = Data_;
    };
    candela(const candela& other) : Data(other.Data), Open(other.Open), High(other.High), Low(other.Low), Volume(other.Volume)  {}
    candela(timp Data_, double Open_, double High_, double Low_, double Close_, double Volume_) : Data{Data_}, Open{Open_}, High(High_), Low(Low_), Close(Close_), Volume(Volume_) {}
    candela(timp Data_, double Open_) : Data{Data_}, Open{Open_} {}
    candela& operator=(const candela& other)
    {
        Data = other.Data;
        Open = other.Open;    //operator =
        High = other.High;
        Low = other.Low;
        Close = other.Close;
        Volume = other.Volume;
        return *this;
    }
    ~candela() {/*std::cout << "Destr candela\n";*/}// destructor
    friend std::ostream& operator<<(std::ostream& os, const candela& st)
    {
        os << "Data: " << st.Data <<" Open: " << st.Open << " High: "<< st.High << " Low: " << st.Low << " Close: "<< st.Close <<" Volume: "<< st.Volume<<"\n";
        return os;
    }
    friend std::istream& operator >> ( std::istream& is, candela& x)
    {
        is >> x.Data >> x.Open >> x.High >> x.Low >> x.Close >> x.Volume;
        return is;
    }


};
std::vector<std::vector<std::string> > parseCSV(std::string src);
class coin
{
protected:
    std::string name ="";
    std::string ticker;
    int cant = 0;
public:
    coin () {}
    coin ( const std::string& name_, const std::string& ticker_, int cant_ ):name (name_), ticker (ticker_), cant(cant_) {}
    coin ( const std::string& name_, const std::string& ticker_) :name (name_), ticker (ticker_)
    {
        cant = 0;
    }
    explicit coin ( const std::string& ticker_):ticker (ticker_){}
    coin ( const coin& x):name(x.name), ticker (x.ticker), cant(x.cant) {}
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
    ~coin() {} // destructor
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
            for  (auto j = (*i).begin(); j!= (*i).end(); ++k,++j)
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
class pereche
{
private:
    coin sell_coin = {"","",0};///coin to sell
    coin buy_coin = {"","",0};///coin to buy
public:
    pereche() {}
    pereche (const coin& sell_coin_, const coin& buy_coin_) :sell_coin(sell_coin_), buy_coin(buy_coin_) {}
    pereche (const pereche& x):sell_coin (x.sell_coin),buy_coin (x.buy_coin) {}
    ~pereche() {}
    pereche& operator = (const pereche &x)
    {
        sell_coin = x.sell_coin;
        buy_coin = x.buy_coin;
        return *this;
    }
    friend std::ostream& operator << (std::ostream& os, const pereche& x)
    {
        os<<"Perechea: \n"<<x.sell_coin<<"\n"<<x.buy_coin;
        return os;
    }
};
class grafic:public coin
{
    private:
        std::string culoare;
        std::list <candela> l;
    public:
        void setCuloare(std::string s)
        {
            culoare = s;
        }
        const std::string getCuloare()
        {
            return culoare;
        }
        grafic (std::string& culoare_ ):culoare (culoare_){}
        grafic () {}
};

int main_close();
void tema1();
void analiza();

int main()
{
    ///     == Functionalitati ==

    ///        == Tema 1 ==
    /// Verificarea/rularea cerintelor de la tema 1
    //tema1();

    ///     == Functionalitatea principala ==
    //analiza();

    ///        == Tema 2 ==
    grafic g1;
    g1.setCuloare ("alb");
    std::cout<<g1.getCuloare()<<std::endl ;

    std::fstream g;
    g.open("coins.txt",std::fstream::in);
    coin x;
    g>>x;
    g>>g1;
    g.close();

    std::cout<<g1;

    ///     == Pentru ca programul sa asptepte apasarea unei taste decomentati urmatoarea linie
    return main_close();
    //return 0;
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

void tema1() /// testarea claselor/ metodelor/ operatorilor din tema 1
{
    std::cout<< "                           == Tema 1 ==\n\n";

    /// Clasa candela

    std::fstream f;
    f.open("date.txt",std::fstream::in);
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
    g.open("coins.txt",std::fstream::in);
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

int main_close()
{
    std::cout<<"\n";
    std::cout<<"Apasa enter pentru a incheia programul!\n";
    //_getch();
    std::cin.get();
    return 0;
}

std::vector<std::vector<std::string> > parseCSV(std::string src)
{
    std::ifstream data(src);
    std::string line;
    std::vector<std::vector<std::string> > parsedCsv;
    while(std::getline(data,line))
    {
        std::stringstream lineStream(line);
        std::string cell;
        std::vector<std::string> parsedRow;
        while(std::getline(lineStream,cell,','))
            parsedRow.push_back(cell);
        parsedCsv.push_back(parsedRow);
    }
    return parsedCsv;

}
