#include"Order.h"
#include"BuyOrder.h"
#include"SellOrder.h"
#include"OrderBook.h"


int main() {
    OrderBook orderBook;

    //// Input: list of pending orders
    //orderBook.addOrder(std::make_shared<BuyLimitOrder>(1, 10, 100.0));
    //orderBook.addOrder(std::make_shared<SellLimitOrder>(2, 5, 105.0));
    //orderBook.addOrder(std::make_shared<BuyStopOrder>(3, 15, 102.0));
    //orderBook.addOrder(std::make_shared<SellStopOrder>(4, 10, 98.0));

    
    orderBook.addOrder(std::make_unique<BuyLimitOrder>(1, 10, 100.0));
    orderBook.addOrder(std::make_unique<SellLimitOrder>(2, 5, 105.0));
    orderBook.addOrder(std::make_unique<BuyStopOrder>(3, 15, 102.0));
    orderBook.addOrder(std::make_unique<SellStopOrder>(4, 10, 98.0));

    // Display initial orders
    std::cout << "Initial Orders:" << std::endl;
    orderBook.display();

    // Input: stream of ticks (price updates)
    std::vector<Tick> ticks = 
    {
        {"09:00", 101.0},
        {"09:01", 100.0},
        {"09:02", 106.0},
        {"09:03", 97.0},
        {"09:04", 99.0}
    };

    // Display final orders
    std::cout << "\n\nFinal Output:" << std::endl;

    // Process each tick and print execution details
    for (const auto& tick : ticks) 
    {
        orderBook.processTick(tick);
    }

    //orderBook.display();

    return 0;
}
