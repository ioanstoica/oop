#include <iostream>
#include <fstream>

class candela{
private:
        int OpenPrice;
    public:
        candela(){OpenPrice = 0;}
        int getOpenPrice()const { return OpenPrice;}
        void setOpenPrice(int OpenPrice_){OpenPrice = OpenPrice_;}
        candela(const candela& other) : OpenPrice{other.OpenPrice}{}
        candela& operator=(const candela& other) {OpenPrice = other.OpenPrice; return *this;}
        ~candela() {std::cout << "Destr candela\n";}
};


int main() {
    std::cout << "Hello, world!\n";
    std::fstream f;
    f.open("date.txt",std::fstream::in);
    int x,n=0,i;
    candela v[100] = {};
    while(f>>x)
        v[++n].setOpenPrice(x);
    for (i=1;i<=n;i++)
        std::cout<<v[i].getOpenPrice()<<std::endl;


    f.close();

    return 0;
}
