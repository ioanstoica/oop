#ifndef TOKEN_H
#define TOKEN_H
#include <coin.h>

class token
{
    protected:
        coin *p;

    public:
        token();
        virtual ~token();
        void setP(coin *p_);
        void print();

};

#endif // TOKEN_H
