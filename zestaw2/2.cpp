//
// Created by Bartłomiej Grzesik on 24/10/2019.
//

#include <iostream>
#include <cmath>

// 2. Napisz program wczytujący liczbę naturalną z klawiatury i odpowiadający
// czy liczba ta jest wielokrotnością dowolnego wyrazu ciągu danego
// wzorem A(n)=n*n+n+1.

int main()
{
    const int l = 13;

    int a = 0;
    for (int n = 1; (a = n * n + n + 1) <= l; ++n) {
        if (l % a == 0) {
            std::cout << "TAK" << std::endl;
            return 0;
        }
    }

}