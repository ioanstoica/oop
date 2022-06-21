#ifndef UTILITY_TOKEN_H
#define UTILITY_TOKEN_H
#include "../include/coin.h"

class utility_token : public coin
{
    protected:

    public:
        utility_token();
        virtual ~utility_token();
        void print() override;



};

#endif // UTILITY_TOKEN_H
