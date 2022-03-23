#include <iostream>
#include <fstream>

class candela{
    public:
        int OpenPrice;
};


int main() {
    std::cout << "Hello, world!\n";
    std::fstream f;
    f.open("date.txt",std::fstream::in);
    int x,n=0,i;
    candela v[100];
    while(f>>x)
        v[++n].OpenPrice = x;
    for (i=1;i<=n;i++)
        std::cout<<v[i].OpenPrice<<std::endl;


    f.close();

    return 0;
}
