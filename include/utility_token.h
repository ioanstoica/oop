#ifndef UTILITY_TOKEN_H
#define UTILITY_TOKEN_H
#include <string>
#include "coin.h"


class utility_token : public coin
{
    protected:
        std::string rol = "";
    public:
        utility_token();
        virtual ~utility_token();
        void print() override;
        utility_token operator = ( const utility_token& x);
        void setRol(const std::string rol_);
        utility_token ( const std::string& name_, const std::string& ticker_, int cant_, const std::string& rol_ ): rol(rol_){name = name_, ticker  = ticker_, cant= cant_;}
        utility_token (  const std::string& rol_ ):rol(rol_) {}
};

#endif // UTILITY_TOKEN_H
