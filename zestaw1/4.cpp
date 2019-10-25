//
// Created by Bartłomiej Grzesik on 24/10/2019.
//

#include <iostream>

// 4. Napisać program obliczający pierwiastek całkowitoliczbowy
// z liczby naturalnej korzystając z zależności 1+3+5+... = n^2.

int main()
{
    const int n = 16;

    int i = 0, p = 0;
    while ((p += ++i * 2 + 1) <= n);

    std::cout << i << std::endl;
}