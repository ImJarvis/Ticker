# Ticker
A first hand solution for a programming challenge. Below is the problem Statement -

Objective:
Create a C++ program to manage and trigger pending orders based on price feed and execute them accordingly.

# Detailed Requirements:
Ticks and What They Mean:
A tick represents a single price update in the market. It contains the latest price information for a financial instrument at a specific point in time.
In this test, you will receive a sequence of ticks, each containing a timestamp and a price. Your task is to process these ticks to update the order book and trigger executions.
Order Book Management:
The order book is a dynamic record of all buy and sell orders for a particular financial instrument.

# Your program should maintain an order book with two main components:
Buy Orders: Orders to purchase the instrument at a specified price or better.
Sell Orders: Orders to sell the instrument at a specified price or better.
Each order in the book should have the following attributes:
Order ID
Type (Buy/Sell)
Quantity
Price
Status (Pending, Executed)
Pending Orders and Conditions for Activation:
# Limit Orders: These are orders to buy or sell at a specific price or better.
A buy limit order is activated when the price feed is equal to or lower than the order price.
A sell limit order is activated when the price feed is equal to or higher than the order price.
# Stop Orders: These are orders that become market orders once a specified price level is reached.
A buy stop order is triggered when the price feed reaches or exceeds the stop price.
A sell stop order is triggered when the price feed falls to or below the stop price.

# Coding Task:
# Input:
A list of pending orders.
A stream of ticks (price updates).
# Output:
Print the execution details of orders triggered by the price feed.
Implementation Details:
Create a class Order to represent an order.
Create a class OrderBook to manage buy and sell orders.
Implement methods to add orders, process ticks, and trigger order execution based on the conditions described above.

#######################################################################################################################################################
Example:
Input:
Pending Orders:
Order 1: Buy Limit, Price: 100, Quantity: 10
Order 2: Sell Limit, Price: 105, Quantity: 5
Order 3: Buy Stop, Price: 102, Quantity: 15
Order 4: Sell Stop, Price: 98, Quantity: 10
Ticks:
[Time: 09:00, Price: 101]
[Time: 09:01, Price: 100]
[Time: 09:02, Price: 106]
[Time: 09:03, Price: 97]
Output:
Order 1 executed at 09:01, Price: 100, Quantity: 10
Order 2 executed at 09:02, Price: 106, Quantity: 5
Order 3 executed at 09:02, Price: 106, Quantity: 15
Order 4 executed at 09:03, Price: 97, Quantity: 10
Explanation:
At 09:01, the price is 100, triggering the execution of the Buy Limit order (Order 1).
At 09:02, the price is 106, triggering the execution of the Sell Limit order (Order 2) and Buy Stop order (Order 3).
At 09:03, the price is 97, triggering the execution of the Sell Stop order (Order 4).
Submission:
Submit your C++ source code file.
Include comments explaining your code logic.
Ensure your code compiles and runs correctly with sample input and output.

Additional Information
This coding test aims to evaluate your understanding and implementation skills in:
Handling real-time data streams.
Managing and updating an order book.
Implementing order triggering mechanisms based on market conditions.
