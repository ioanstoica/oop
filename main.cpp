///Tema 2

#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <math.h>
#include <ctime>


class timp
{
private:
    int an = 0;
    int luna = 0;
    int zi = 0;
public:
    timp () {}
    timp (int an_, int luna_, int zi_) :an(an_), luna(luna_), zi(zi_) {}
    timp (timp& t): an(t.an), luna(t.luna), zi(t.zi) {}
    timp (const char s[])
    {
        char s_aux[11];
        strcpy(s_aux,s);
        s_aux[4]=s_aux[7]=0;
        an = atoi(s_aux);
        luna = atoi(s_aux+5);
        zi = atoi(s_aux+8);
    }
    ~timp () {}
    timp operator = (const timp t)
    {
        an = t.an;
        luna = t.luna;
        zi = t.zi;
        return *this;
    }
    friend std::ostream& operator << (std::ostream& os, const timp& t)
    {
        char aux_luna[2]="",aux_zi[3]="";
        if(t.luna<=9)
            strcpy(aux_luna,"0");
        if(t.zi<=9)
            strcpy(aux_zi,"0");
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
    bool operator < (timp &t)
    {
        if((*this).an != t.an)
            return (*this).an < t.an;
        if((*this).luna != t.luna)
            return (*this).luna < t.luna;
        return (*this).zi < t.zi;
    }
    bool operator > (timp &t)
    {
        return t < (*this);
    }
    timp operator = (timp &t)
    {
        (*this).an = t.an;
        (*this).luna = t.luna;
        (*this).zi = t.zi;
        return (*this);
    }
    bool operator == (timp &t)
    {
        return !((*this) < t ) && !( (*this) > t );
    }
    bool operator <= (timp &t)
    {
        return (*this) < t || (*this) == t ;
    }
    bool operator >= (timp &t)
    {
        return (*this) > t || (*this) == t ;
    }

};
class candela
{
private:
    int Data = 0;
    int OpenPrice = 0;
public:
    candela() {}
    int getOpenPrice()const
    {
        return OpenPrice;
    }
    int getData()const
    {
        return Data;
    }
    void setOpenPrice(int OpenPrice_)
    {
        OpenPrice = OpenPrice_;
    }
    void setData(int Data_)
    {
        Data = Data_;
    };
    candela(const candela& other) : Data(other.Data), OpenPrice(other.OpenPrice) {}
    candela(int Data_, int OpenPrice_) : Data{Data_}, OpenPrice{OpenPrice_} {}
    candela& operator=(const candela& other)
    {
        OpenPrice = other.OpenPrice;    //operator =
        Data = other.Data;
        return *this;
    }
    ~candela() {/*std::cout << "Destr candela\n";*/}// destructor
    friend std::ostream& operator<<(std::ostream& os, const candela& st)
    {
        os << "Data: " << st.Data <<" pret: " << st.OpenPrice << "\n";
        return os;
    }
    friend std::istream& operator >> ( std::istream& is, candela& x)
    {
        is >> x.Data >> x.OpenPrice ;
        return is;
    }

};
class coin
{
private:
    std::string name;
    std::string ticker;
    int cant = 0;
public:
    coin () {}
    coin ( const std::string& name_, const std::string& ticker_, int cant_ ):name (name_), ticker (ticker_), cant(cant_) {}
    coin ( const std::string& name_, const std::string& ticker_) :name (name_), ticker (ticker_)
    {
        cant = 0;
    }
    coin ( const std::string& ticker_):ticker (ticker_)
    {
        name = "";
        cant = 0;
    }
    coin ( const coin& x):name(x.name), ticker (x.ticker), cant(x.cant) {}
    friend std::ostream& operator << (std::ostream& os, const coin& x)
    {
        os << "Name: "<<x.name<<", ticker: "<<x.ticker<<", cantitate: "<<x.cant <<"\n";
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
    coin operator + ( coin& x)
    {
        coin a(*this);
        a.cant += x.cant;
        return a;
    }
    coin operator - ( coin& x)
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
    coin operator - (int& x)
    {
        coin a(*this);
        a.cant -= x;
        return a;
    }
    /*void evolutie ( timp DataInitiala, timp DataFinala)
    {
        if ( DataFinala < DataInitiala)
        {
            std::cout<<"Eroare: DataInitiala > DataFinala "<<std::endl;
            return;
        }
        std::string fisier = (*this).ticker + ".txt";
        std::cout<< "Datele se afla in fisierul: "<< fisier<< std::endl;
        std::fstream f;
        f.open(fisier,std::fstream::in);

        candela c;
        int PretInitial = -1, PretFinal = -1;
        while(f>>c)
        {
            int Data = c.getData();
            if (Data == DataInitiala )
                PretInitial = c.getOpenPrice();
            if (Data == DataFinala)
                PretFinal = c.getOpenPrice();
        }
        std::cout<<"PretulInitial: " << PretInitial<<" PretFinal: " <<PretFinal<< std::endl;
        float modificarePret = float(float(PretFinal - PretInitial) / float(PretInitial));
        if (modificarePret >= 0)
            std::cout << "Pretul a crescut cu: " << modificarePret *100 <<"%\n";
        else
            std::cout << "Pretul a scazut cu: " << modificarePret *100 <<"%\n";

        int NrAni = DataFinala - DataInitiala ;
        if (NrAni > 1 ) /// PretInitial * (1+ModificareaAnuala)^NrAni = PretFinal => (1+ModificareaAnuala)^NrAni = PretFinal/PretInitial => 1+ModificareaAnuala = (PretFinal/PretInitial)^(1/NrAni) => ModificareaAnuala = (PretFinal/PretInitial)^(1/NrAni) -1
        {
            float ModificareaAnuala = pow(float(PretFinal)/float(PretInitial),1/float(NrAni)) -1 ;
            std::cout<<"In cei " << NrAni <<" ani "<< "modificarea medie anuala a pretului a fost de: " << ModificareaAnuala * 100 <<"%\n" ;
        }

        f.close();
        return;
    }*/
};
class pereche
{
private:
    coin sell_coin = {"","",0};///coin to sell
    coin buy_coin = {"","",0};///coin to buy
public:
    pereche() {}
    pereche (coin& sell_coin_, coin& buy_coin_) :sell_coin(sell_coin_), buy_coin(buy_coin_) {}
    pereche ( pereche& x):sell_coin (x.sell_coin),buy_coin (x.buy_coin) {}
    ~pereche() {}
    pereche operator = (const pereche x)
    {
        sell_coin = x.sell_coin;
        buy_coin = x.buy_coin;
        return *this;
    }
    friend std::ostream& operator << (std::ostream& os, const pereche& x)
    {
        os<<"Perechea: \n"<<x.sell_coin<<x.buy_coin;
        return os;
    }
};
int main_close()
{
    char y;
    std::cout<<"\n";
    std::cout<<"Trimite orice caracter pentru a incheia programul!\n";
    std::cin>> y;
    return 0;
}
tm* convert_string_to_tm(const char data[]) /// convert string de forma "yyyy-mm-dd" in structura de forma tm
{
    tm *ltm = new tm;
    char data_aux[11];
    for(int i=0; i<=10; i++)
        data_aux[i] = data[i];
    data_aux[4] = 0;
    ltm->tm_year = atoi(data_aux) - 1900;
    data_aux[7] = 0;
    ltm->tm_mon = atoi(data_aux+5) - 1;
    ltm->tm_mday = atoi(data_aux+8);
    return ltm;
}
void print(tm* ltm)
{
    // print various components of tm structure.
    std::cout << "Year:" << 1900 + ltm->tm_year<<std::endl;
    std::cout << "Month: "<< 1 + ltm->tm_mon<< std::endl;
    std::cout << "Day: "<< ltm->tm_mday << std::endl;
    //std::cout << "Time: "<< 5+ltm->tm_hour << ":";
    //std::cout << 30+ltm->tm_min << ":";
    //std::cout << ltm->tm_sec << std::endl;
}
int main()
{
    /// Tema 1

    /// Clasa candela
    bool print_all = 1;

    if (print_all == 1 )
    {
        std::fstream f;
        f.open("date.txt",std::fstream::in);
        candela c;
        std::cout<<"Fisierul cu preturi:\n";
        while(f>>c)
            std::cout<<c;
        std::cout<<"\n";
        f.close();

        std::cout<<"Exemple de candele: \n";
        candela c1;
        candela c2(1, 40000), c3(2, 63200);
        std::cout<< c1<< c2<< c3;
        std::cout<<"\n";

        ///Clasa coin
        std::fstream g;
        g.open("coins.txt",std::fstream::in);
        coin x;
        std::cout<<"Fisierul cu monede:\n";
        while(g>>x)
            std::cout<<x;
        std::cout<<"\n";
        g.close();

        coin x3("Bitcoin","BTC",13),x4("Bitcoin","BTC",200),x5("Bitcoin","BTC",24000);
        std::cout<<"Adunari si scaderi:\n"<<x3+x4<<x5+89+x4<<"\n";

        ///Clasa pereche
        coin x1("Egold","EGLD",1), x2("FutureCoin", "FUTURE", 150000);
        pereche p1, p2(x1,x2);
        std::cout<<"Perechi:\n"<<p1<<p2<<std::endl;
        std::cout<<std::endl;


    }
    /// Tema 2
    /// Datale istorice ale ficarei monede se afla intr-un fisier de forma tixker-USD.txt , ex: BTC-USD.txt

    /// Cresterea pretului de la data DataInitiala la data DataFinala a fost:
    coin btc("Bitcoin","BTC",100);
    timp DataInitiala( "2018-02-01") , DataFinala ( "2019-01-02" );
    std::cout << "Analizam: " << btc << "De la data " << DataInitiala << " la data " <<DataFinala << "\n";

    //btc.evolutie ( DataInitiala, DataFinala);
    ///Time tests:
    //timp t = DataFinala;
    //std::cout<<( DataFinala <= DataInitiala );


    return main_close();
}
