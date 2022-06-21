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
    for(int i=0; i<=10; i++)
        s_aux[i] = s[i];
    s_aux[4]=s_aux[7]=0;
    an = atoi(s_aux);
    luna = atoi(s_aux+5);
    zi = atoi(s_aux+8);
}
std::ostream& operator << (std::ostream& os, const timp& t)
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
std::istream& operator >> (std::istream& is, timp& t)
{
    char m,s,z,u,z2,u2,z3,u3,sep;
    is>>m>>s>>z>>u>>sep>>z2>>u2>>sep>>z3>>u3;
    t.an = 1000*(m-'0')+100*(s-'0')+10*(z-'0')+u-'0';
    t.luna = 10*(z2-'0')+u2-'0';
    t.zi = 10*(z3-'0')+u3-'0';
    return is;
}
bool timp::operator < (const timp &t)const
{
    if((*this).an != t.an)
        return (*this).an < t.an;
    if((*this).luna != t.luna)
        return (*this).luna < t.luna;
    return (*this).zi < t.zi;
}
bool timp::operator > (const timp &t)const
{
    if((*this).an != t.an)
        return (*this).an > t.an;
    if((*this).luna != t.luna)
        return (*this).luna > t.luna;
    return (*this).zi > t.zi;
}
timp & timp::operator = (const timp &t)
{
    (*this).an = t.an;
    (*this).luna = t.luna;
    (*this).zi = t.zi;
    return (*this);
}
bool timp::operator == (const timp &t)const
{
    return !((*this) < t ) && !( (*this) > t );
}
bool timp::operator <= (const timp &t)const
{
    return (*this) < t || (*this) == t ;
}
bool timp::operator >= (const timp &t)const
{
    return (*this) > t || (*this) == t ;
}
