//
// Created by Bartłomiej Grzesik on 24/10/2019.
//

#include <iostream>
#include <cmath>

// 6. Napisać program rozwiązujący równanie x^x=2019 metodą bisekcji.

int main() {
    const int n = 2019;


    int a = n;
    int b = n;

    while (b != 1) {
        b /= 2;

        int apn = abs((a + b) * (a + b) - n);
        int amn = abs((a - b) * (a - b) - n);
        int an = abs(a * a - n);

        if (apn < an && apn < amn) {
            a += b;
        } else if (amn < an && amn < apn) {
            a -= b;
        }
    }

}