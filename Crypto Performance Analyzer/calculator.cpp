#include <iostream>
#include "calculator.h"

// Forward declarations (or place these in calculator.h)
void calc_now();
void calc_month();
void calc_year();

void beginprocess()
{
    int type;
    std::cout << "NOTE: THIS IS NOT 100% ACCURATE. USE NUMBERS AND DECIMAL POINTS ONLY (NO COMMAS)!\n\n";
    std::cout << "What do you want to calculate?\n"
        << "  1) Current total portfolio value in $\n"
        << "  2) Estimated earnings in a month\n"
        << "  3) Estimated earnings in a year\n"
        << "Enter choice (1-3): ";

    std::cin >> type;

    if (std::cin.fail()) {
        std::cout << "\nInvalid input. Please run the program again with a number.\n";
        return;
    }

    switch (type)
    {
    case 1:
        calc_now();
        break;
    case 2:
        calc_month();
        break;
    case 3:
        calc_year();
        break;
    default:
        std::cout << "\nInvalid selection. Please choose 1, 2, or 3.\n";
        break;
    }
}

void calc_now()
{
    double btc_price;
    double btc_amount;

    std::cout << "How much is 1 BTC equal to in $: ";
    std::cin >> btc_price;
    std::cout << "How much BTC do you currently hold: ";
    std::cin >> btc_amount;

    std::cout << "\nCurrently, your bitcoin is worth $" << (btc_price * btc_amount) << "\n";
}

void calc_month()
{
    double btc_price;
    double hourly_btc;

    std::cout << "How much is 1 BTC equal to in $: ";
    std::cin >> btc_price;
    std::cout << "How much BTC do you earn per hour: ";
    std::cin >> hourly_btc;

    double monthly_usd = hourly_btc * btc_price * 24.0 * 30.0;

    std::cout << "\nIn 1 month (approx. 30 days), you will earn approximately $" << monthly_usd << "\n";
}

void calc_year()
{
    double btc_price;
    double hourly_btc;

    std::cout << "How much is 1 BTC equal to in $: ";
    std::cin >> btc_price;
    std::cout << "How much BTC do you earn per hour: ";
    std::cin >> hourly_btc;

    double yearly_usd = hourly_btc * btc_price * 24.0 * 365.0;

    std::cout << "\nIn 1 year (365 days), you will earn approximately $" << yearly_usd << "\n";
}