#include<iostream>
#include<cmath>

int main() {
    float a, b, c;
    std::cout << "Enter coefficients a, b, c = ";
    std::cin >> a >> b >> c;

    float delta = b*b - 4*a*c;

    if (delta > 0) {
        std::cout << "Solution 2 = " << (-b - sqrt(delta))/(2.0*a) << std::endl;
        std::cout << "Solution 1 = " << (-b + sqrt(delta))/(2.0*a) << std::endl;
    }
    else if (delta == 0)
        std::cout << "Solution 1 = " << -b/(2.0*a) << std::endl;
    else
        std::cout << "No solution!" << std::endl;

    return 0;
}