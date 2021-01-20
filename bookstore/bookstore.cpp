#include <iostream>
#include <string>
#include "Sales_data.h"



int main() 
{
    Sales_data data1, data2;

    double price = 0; // price per book, used to calculate total revenue 
    // read the first transactions: ISBN, number of books sold, price per book
    std::cin >> data1.bookNo >> data1.units_sold >> price; // calculate total revenue from price and units_sold
    data1.revenue = data1.units_sold * price;

    // read the second transaction
    std::cin >> data2.bookNo >> data2.units_sold >> price; data2.revenue = data2.units_sold * price;

    if (data1.bookNo == data2.bookNo) {
        unsigned totalCount = data1.units_sold + data2.units_sold;
        double totalRevenue = data1.revenue + data2.revenue;
        std::cout << data1.bookNo << " " << totalCount << " " << totalRevenue << " " ;
        if (totalCount != 0) {
            std::cout << totalRevenue / totalCount << std::endl;
        }
        else {
            std::cout << "(No sales)" << std::endl; 
        }
        return 0;
    } else {
        std::cerr << "Data must be on same book identifier (ISNB)" << std::endl;
        return -1;
    }
    // std::cout << "Enter two numbes:" << std::endl;
    // int v1 = 0, v2 = 0;
    // std::cin >> v1 >> v2;
    // std::cout << "The sum of " << v1 << " and " << v2 << " is " << v1 + v2 << std::endl;
    // return 0;
}