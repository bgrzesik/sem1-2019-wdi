//
// Created by Bartłomiej Grzesik on 24/10/2019.
//

#include <iostream>
#include <cmath>
#include <iomanip>

// 3. Napisz program wczytujący liczbę naturalną z klawiatury i odpowiadający
// czy liczba naturalna jest palindromem, a następnie czy jest palindromem dwójkowym.

int main()
{
    uint x = 121020121;

    uint n10 = log10(x);

    for (int i = 0; i <= n10 / 2; ++i) {
        uint r = pow(10, n10 - i);
        uint l = pow(10, i);

        if ((x / r) % 10 != (x / l) % 10) {
            std::cout << "NIE 10" << std::endl;
            break;
        }
        if (r / 10 <= l) {
            std::cout << "TAK 10" << std::endl;
            break;
        }
    }


    // Binarnie

    x = 0b1101001011;

    if (x == 0) {
        std::cout << "TAK 2" << std::endl;
        return 0;
    }

    uint r = x;
    r |= r >> 16;
    r |= r >> 8;
    r |= r >> 4;
    r |= r >> 2;
    r |= r >> 1;
    r ^= r >> 1;
    uint l = 1;

    while (r >= l) {
        if (((x & r) != 0) != ((x & l) != 0)) {
            std::cout << "NIE 2" << std::endl;
            return 0;
        }
        r >>= 1;
        l <<= 1;
    }
    std::cout << "TAK 2" << std::endl;

}