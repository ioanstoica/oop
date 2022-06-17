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
}

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

std::ostream& operator<<(std::ostream& os, const candela& st)
    {
        os << "Data: " << st.Data <<" Open: " << st.Open << " High: "<< st.High << " Low: " << st.Low << " Close: "<< st.Close <<" Volume: "<< st.Volume<<"\n";
        return os;
    }

std::istream& operator >> ( std::istream& is, candela& x)
    {
        is >> x.Data >> x.Open >> x.High >> x.Low >> x.Close >> x.Volume;
        return is;
    }
