#pragma once
#include"Order.h"

class BuyLimitOrder : public Order
{
public:
    BuyLimitOrder(int id, int quant, float pr):Order(id,quant,pr,OrderType::BuyLimit)
    {
    }

    bool shouldExecute(const Tick& tick) const override 
    {
        return tick.price <= getPrice();
    }

    std::string_view getTypeString() const override
    {
        return "Buy Limit";
    }
};

class BuyStopOrder : public Order
{
public:
    BuyStopOrder(int id, int quant, float pr) :Order(id, quant, pr, OrderType::BuyStop)
    {
    }

    bool shouldExecute(const Tick& tick) const override
    {
        return tick.price >= getPrice();
    }

    std::string_view getTypeString() const override
    {
        return "Buy Stop";
    }

};