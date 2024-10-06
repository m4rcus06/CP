#include <iostream>

int main() {
    int n;
    int a = 1, d = 0; // N!, S
    float b = 0.0, c = 1.0; //ln(2), PI

    std::cout << "Enter a integer = ";
    std::cin >> n;

    int alternate = -1;
    for (int i  = 1; i <= n; i++) {
        alternate *= -1;
        a *= i;
        b += 1.0/(i*alternate);
        c += 1.0/((i*2 + 1)*alternate*-1);
        if (i*i <= n)
            d += i*i;
    }

    std::cout << "N! = " << a << '\n'
              << "ln(2) = " << b << '\n'
              << "PI = " << 4.0*c << '\n'
              << "S = " << d << '\n';
}