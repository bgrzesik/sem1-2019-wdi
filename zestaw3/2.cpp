//
// Created by Bartłomiej Grzesik on 24/10/2019.
//

#include <iostream>
#include <cmath>

// 2. Napisać program wczytujący dwie liczby naturalne i odpowiadający na pytanie
// czy są one zbudowane z takich samych cyfr, np. 123 i 321, 1255 i 5125, 11000 i 10001.

int digit_count[10];

int main()
{
    int a = 11000;
    int b = 10001;

    while (a > 0) {
        digit_count[a % 10]++;
        a /= 10;
    }

    while (b > 0) {
        digit_count[b % 10]--;
        b /= 10;
    }

    for (int i = 0; i < 10; ++i) {
        if (digit_count[i] != 0) {
            std::cout << "NIE" << std::endl;
            return 0;
        }
    }

    std::cout << "TAK" << std::endl;

}