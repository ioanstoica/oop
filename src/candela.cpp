#include "../include/candela.h"

candela::candela()
{

}

timp  candela::getData()
{
    return Data;
}

void candela::setOpen(double Open_)
{
    Open = Open_;
}

void candela::setData(timp Data_)
{
    Data = Data_;
};

candela& candela::operator=(const candela& other)
    {
        Data = other.Data;
        Open = other.Open;    //operator =
        High = other.High;
        Low = other.Low;
        Close = other.Close;
        Volume = other.Volume;
        return *this;
    }
