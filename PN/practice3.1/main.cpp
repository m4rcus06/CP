#include<iostream>

int main() {
    int x, y, res = -1;
    char op;

    std::cout << "Enter two integers = ";
    std::cin >> x >> y;
    std::cout << "Enter an opertor (+, -, *, /, %) = ";
    std::cin.ignore(1000, '\n');
    std::cin >> op;

    if (y == 0 && (op == '/' || op == '%')) {
        std::cout << "Error: divided by zero.\n";
        return 0;
    }

    switch (op)
    {
        case '+':
            res = x+y;
            break;
        case '-':
            res = x-y;
            break;
        case '*':
            res = x*y;
            break;
        case '/':
            res = x/y;
            break;
        case '%':
            res = x%y;
            break;
        
        default:
            return 0;
    }

    std::cout << "Result = " << res << std::endl;

    return 0;
}