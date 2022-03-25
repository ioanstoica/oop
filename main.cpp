///Tema 2

#include <iostream>
#include <fstream>
#include <string.h>
class candela
{
private:
    int OpenPrice;
public:
    candela()
    {
        OpenPrice = 0;
    }
    int getOpenPrice()const
    {
        return OpenPrice;
    }
    void setOpenPrice(int OpenPrice_)
    {
        OpenPrice = OpenPrice_;
    }
    candela(const candela& other) : OpenPrice{other.OpenPrice} {}
    candela(int OpenPrice_) : OpenPrice{OpenPrice_}{}
    candela& operator=(const candela& other)
    {
        OpenPrice = other.OpenPrice;    //operator =
        return *this;
    }
    ~candela() {/*std::cout << "Destr candela\n";*/}// destructor
    friend std::ostream& operator<<(std::ostream& os, const candela& st)
    {
        os << "Price: " << st.OpenPrice << "\n";
        return os;
    }
    friend std::istream& operator >> ( std::istream& os, candela& x)
    {
        os >> x.OpenPrice ;
        return os;
    }
};
class coin
{
private:
    std::string name;
    std::string ticker;
    int cant;
public:
    coin()
    {
        name = "";
        ticker = "";
        cant = 0;
    }
    coin ( const std::string& name_, const std::string& ticker_, int cant_ )
    {
        name = name_;
        ticker = ticker_;
        cant = cant_;
    }
    coin ( const std::string& name_, const std::string& ticker_)
    {
        name = name_;
        ticker = ticker_;
        cant = 0;
    }
    coin ( const std::string& ticker_)
    {
        name = "";
        ticker = ticker_;
        cant = 0;
    }
    coin ( const coin& x)
    {
        name = x.name;
        ticker = x.ticker;
        cant = x.cant;
    }
    friend std::ostream& operator << (std::ostream& os, const coin& x)
    {
        os << "Name: "<<x.name<<", ticker: "<<x.ticker<<", cantitate: "<<x.cant<<"\n";
        return os;
    }
    friend std::istream& operator >> ( std::istream& os, coin& x)
    {
        os >> x.name >> x.ticker >> x.cant;
        return os;
    }
    coin operator = ( const coin& x)
    {
        name = x.name;
        ticker = x.ticker;
        cant = x.cant;
        return *this;
    }
    ~coin(){} // destructor
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
    coin operator + ( const int& x)
    {
        coin a(*this);
        a.cant += x;
        return a;
    }
    coin operator - (const int& x)
    {
        coin a(*this);
        a.cant -= x;
        return a;
    }
};
class pereche
{
private:
    coin coin1;///coin to sell
    coin coin2;///coin to buy
public:
    pereche()
    {
        coin1 = {"","",0};
        coin2 = {"","",0};
    }
    pereche (coin& coin1_, coin& coin2_)
    {
        coin1 = coin1_;
        coin2 = coin2_;
    }
    pereche ( pereche& x)
    {
        coin1 = x.coin1;
        coin2 = x.coin2;
    }
    ~pereche(){}
    pereche operator = (const pereche x)
    {
        coin1 = x.coin1;
        coin2 = x.coin2;
        return *this;
    }
    friend std::ostream& operator << (std::ostream& os, const pereche& x)
    {
        os<<"Perechea: \n"<<x.coin1<<x.coin2;
        return os;
    }
};


int main()
{
    /// Clasa candela
    std::fstream f;
    f.open("date.txt",std::fstream::in);
    candela c;
    std::cout<<"Fisierul cu preturi:\n";
    while(f>>c)
        std::cout<<c;
    std::cout<<"\n";
    f.close();

    std::cout<<"Exemple de candele: \n";
    candela c1, c2({40000}), c3(63200);
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
    std::cout<<"Perechi:\n"<<p1<<p2;

    return 0;
}
