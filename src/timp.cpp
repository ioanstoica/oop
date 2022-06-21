#include "../include/timp.h"

timp::timp()
{
    //ctor
}
timp::timp (int an_, int luna_, int zi_) :an(an_), luna(luna_), zi(zi_) {}
int timp::getAn ()
{
    return an;
}
timp::~timp()
{
    //dtor
}

timp::timp (const char *s)
{
    char s_aux[11];
    for(int i=0;i<=10;i++)
        s_aux[i] = s[i];
    s_aux[4]=s_aux[7]=0;
    an = atoi(s_aux);
    luna = atoi(s_aux+5);
    zi = atoi(s_aux+8);
}
