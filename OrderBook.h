#pragma once
#include<vector>
#include"Order.h"


// Helper class to improve the design and make OrderBook class lossely coupled
// Ideally this class will be kept in OrderBook.cpp  but due to limited scope of this project
// I am not creating a seperate translation unit for these classes.

namespace 
{
    class ExecuteService
    {
    public:
        void printExecution(const Order& order, const Tick& tick) const 
        {
            std::cout << "Order " << order.getOrderID() << " executed at " << tick.timeStamp
                << " Price: " << tick.price
                << " Quantity: " << order.getQuantity()
                << std::endl;
        }
    };
}


class OrderBook
{
private:
    //std::vector<std::shared_ptr<Order>> orders;
    std::vector<std::unique_ptr<Order>> orders;
    ExecuteService execute;

public:

    void addOrder(std::unique_ptr<Order> order)
    {
        orders.emplace_back(std::move(order));
    }

    void processTick(const Tick& currentTick)
    {
        for (auto& order : orders)
        {
            if (order->getStatus() == OrderStatus::Pending && order->shouldExecute(currentTick))
            {
                order->setOrderStatus(OrderStatus::Executed);
                execute.printExecution(*order, currentTick);
            }
        }
    }

    void display() const
    {
        for (const auto& order : orders)
            order->displayOrder();
    }
};