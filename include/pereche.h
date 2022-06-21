#ifndef PERECHE_H
#define PERECHE_H
#include "coin.h"

class pereche
{
private:
    coin sell_coin = {"","",0};///coin to sell
    coin buy_coin = {"","",0};///coin to buy
public:
    pereche();
    virtual ~pereche();
    pereche (const coin& sell_coin_, const coin& buy_coin_) :sell_coin(sell_coin_), buy_coin(buy_coin_) {}
    pereche (const pereche& x):sell_coin (x.sell_coin),buy_coin (x.buy_coin) {}
    pereche& operator = (const pereche &x);
    friend std::ostream& operator << (std::ostream& os, const pereche& x);
};

#endif // PERECHE_H
