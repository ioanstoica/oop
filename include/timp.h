#ifndef TIMP_H
#define TIMP_H
#include <iostream>


class timp
{
private:
    int an = 0;
    int luna = 0;
    int zi = 0;
public:
    timp ();
    timp (int an_, int luna_, int zi_);
    timp (const timp &t): an(t.an), luna(t.luna), zi(t.zi) {}
    explicit timp (const char *s);
    ~timp ();
    int getAn ();
    friend std::ostream& operator << (std::ostream& os, const timp& t);
    friend std::istream& operator >> (std::istream& is, timp& t);
    bool operator < (const timp &t)const;
    bool operator > (const timp &t)const;
    timp &operator = (const timp &t);
    bool operator == (const timp &t)const;
    bool operator <= (const timp &t)const;
    bool operator >= (const timp &t)const;
};

#endif // TIMP_H
