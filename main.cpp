///Tema 2
#include <iostream>

using namespace std::literals;

int main_close();
void tema1();
void tema2();
void analiza();

int main()
{
    ///     == Functionalitati ==

    ///        == Tema 1 ==
    /// Verificarea/rularea cerintelor de la tema 1
    tema1();

    ///     == Functionalitatea principala ==
    analiza();

    ///        == Tema 2 ==
    tema2();

    ///     == Pentru ca programul sa asptepte apasarea unei taste decomentati urmatoarea linie
    //return main_close();
    return 0;
}




/*int main_close()
{
    std::cout<<"\n";
    std::cout<<"Apasa enter pentru a incheia programul!\n";
    //_getch();
    std::cin.get();
    return 0;
}*/


