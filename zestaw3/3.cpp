//
// Created by Bartłomiej Grzesik on 24/10/2019.
//

#include <iostream>
#include <cmath>

// 3. Napisać program generujący i wypisujący liczby pierwsze mniejsze od N metodą Sita Eratostenesa

bool bitmask[6400]; // 6400 liczb pierwszych

int main()
{
    const uint n = 200;

    for (int i = 2; i < n; ++i) {
        if (!bitmask[i]) {
            std::cout << i << std::endl;
            for (int j = i + i; j < n; j += i) {
                bitmask[j] = true;
            }
        }
    }

}