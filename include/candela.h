#ifndef CANDELA_H
#define CANDELA_H
#include <iostream>
#include "timp.h"

class candela
{
private:
    timp Data{"0000-00-00"}; ///format "yyyy-mm-dd"
    double Open = 0, High = 0,Low = 0, Close = 0, Volume = 0;
public:
    candela();
    double getOpen()const
    {
        return Open;
    }
    timp getData();
    void setOpen(double Open_);
    void setData(timp Data_);
    candela(const candela& other) : Data(other.Data), Open(other.Open), High(other.High), Low(other.Low), Volume(other.Volume)  {}
    candela(timp Data_, double Open_, double High_, double Low_, double Close_, double Volume_) : Data{Data_}, Open{Open_}, High(High_), Low(Low_), Close(Close_), Volume(Volume_) {}
    candela(timp Data_, double Open_) : Data{Data_}, Open{Open_} {}
    candela& operator=(const candela& other);
    ~candela() {/*std::cout << "Destr candela\n";*/}// destructor
    friend std::ostream& operator<<(std::ostream& os, const candela& st)
    {
        os << "Data: " << st.Data <<" Open: " << st.Open << " High: "<< st.High << " Low: " << st.Low << " Close: "<< st.Close <<" Volume: "<< st.Volume<<"\n";
        return os;
    }
    friend std::istream& operator >> ( std::istream& is, candela& x)
    {
        is >> x.Data >> x.Open >> x.High >> x.Low >> x.Close >> x.Volume;
        return is;
    }


};

#endif // CANDELA_H
