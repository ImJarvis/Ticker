#pragma once

#include"Order.h"

class SellLimitOrder : public Order {
public:
    SellLimitOrder(int id, int quantity, float price)
        : Order(id, quantity, price,OrderType::SellLimit) {}

    bool shouldExecute(const Tick& tick) const override {
        return tick.price >= getPrice();
    }

    std::string_view getTypeString() const override {
        return "Sell Limit";
    }
};


class SellStopOrder : public Order {
public:
    SellStopOrder(int id, int quantity, float price)
        : Order(id, quantity, price, OrderType::SellStop) {}

    bool shouldExecute(const Tick& tick) const override {
        return tick.price <= getPrice();
    }

    std::string_view getTypeString() const override {
        return "Sell Stop";
    }
};
