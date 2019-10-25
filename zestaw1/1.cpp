//
// Created by Bartłomiej Grzesik on 24/10/2019.
//

#include <iostream>

// 1. Napisać program wypisujący elementy ciągu Fibonacciego mniejsze od miliona.

int main()
{
    int n = 1;
    int l = n;

    while (n < 1'000'000) {
        std::cout << n << std::endl;
        int a = n + l;
        l = n;
        n = a;
    }

}