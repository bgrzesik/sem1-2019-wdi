//
// Created by Bartłomiej Grzesik on 24/10/2019.
//

#include <iostream>
#include <cmath>

// 7. Napisać program wczytujący liczbę naturalną z klawiatury i
// rozkładający ją na iloczyn 2 liczb o najmniejszej różnicy.
// Np. 30=5*6, 120=10*12.

int main()
{
    const int n = 30;

    int l = floor(sqrt(n));

    while (l >= 1) {
        if (n % l == 0) {
            break;
        }
        l--;
    }

    std::cout << l << " " << (n / l) << std::endl;
}