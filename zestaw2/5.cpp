//
// Created by Bartłomiej Grzesik on 24/10/2019.
//

#include <iostream>
#include <cmath>

// 5. Napisać program, który wyznacza ostatnia
// niezerową cyfra N! Program powinien działać dla N rzędu 1000000.

int D2(int n)
{
    // 2 4 8 6
    switch ((n - 1) % 4 + 1) {
        case 1: return 2;
        case 2: return 4;
        case 3: return 8;
        case 4: return 6;
    }
//    return int(pow(2, (n - 1) % 4 + 1)) % 10;
}

int D(int n)
{
    switch (n) {
        case 0: return 1; // 1
        case 1: return 1; // 1
        case 2: return 2; // 2
        case 3: return 6; // 6
        case 4: return 4; // 24
        case 5: return 2; // 120
        default: return (D(n / 5) * D2(n / 5) * D(n % 5)) % 10;
    }
}

int main()
{
    std::cout << D(5) << std::endl;    // 2
    std::cout << D(501) << std::endl;  // 4
    std::cout << D(1000) << std::endl; // 2
    std::cout << D(1001) << std::endl; // 2
    std::cout << D(20) << std::endl;   // 4
    std::cout << D(16) << std::endl;   // 8

    std::cout << D(10000) << std::endl;
}