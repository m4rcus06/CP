#include<iostream>

int main() {
    int month, year;
    std::cout << "Enter month and year = ";
    std::cin >> month >> year;

    int days = 31;
    if (month == 4 || month == 6 || month == 9 || month == 11)
        days = 30;
    else if (month == 2) {
        days = 28;
        if (year%400 == 0 || (year%100 != 0 && year%4 == 0))
            days = 29;
    }

    std::cout << "Month " << month << " in year " << year << " has " << days << " days.";

    return 0;
}