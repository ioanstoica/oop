#include "timp.h"

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
