#pragma once
#include<string>
#include<iostream>
enum class OrderType{BuyStop,BuyLimit,SellStop,SellLimit};
enum class OrderStatus{Executed,Pending};

struct Tick
{
    std::string timeStamp;
    float price;
};

class Order 
{
private:
    int orderId;
    int quantity;
    float price;
    OrderStatus status;
    OrderType type;

public:
    int getOrderID() const { return orderId; }
    int getQuantity() const { return quantity; }
    float getPrice() const { return price; }
    OrderType getType() const { return type; }
    OrderStatus getStatus() const { return status; }

    Order(const Order& ref) = default; // copy constructor
    virtual ~Order() = default;  // destructor
    Order& operator=(const Order& ref) = default; // copy assignment
    Order(Order&& ref) = default; // move constructor

    
    void setOrderStatus(OrderStatus newStatus) { status = newStatus; }

    // constructor 
    Order(int Id, int quant, float pr, OrderType o_type)
        :orderId(Id),quantity(quant),price(pr),type(o_type),status(OrderStatus::Pending)
    {

    }

    void displayOrder() const
    {
        std::cout << "Order ID: " << orderId
            << ", Type: " << getTypeString()
            << ", Quantity: " << quantity
            << ", Price: " << price
            << ", Status: " << (status == OrderStatus::Pending ? "Pending" : "Executed")
            << std::endl;

    }


    virtual bool shouldExecute(const Tick& tick) const = 0;
    virtual std::string_view getTypeString() const = 0;

};
