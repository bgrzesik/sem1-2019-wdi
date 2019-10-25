//
// Created by Bartłomiej Grzesik on 24/10/2019.
//

#include <iostream>
#include <cmath>

// 9. Pewnych liczb nie można przedstawić jako sumy elementów spójnych fragmentów ciągu Fibonacciego,
// np. 9,14,15,17,22. Proszę napisać program, który wczytuje liczbę naturalną n,
// wylicza i wypisuje następną taką liczbę większą od n. Można założyć, że 0<n<1000.

int main()
{
    const int n = 22;

    int fib = 1;
    int lfib = 1;

    int fib2 = 1;
    int lfib2 = 1;

    while (fib < n) {
        int nfib = fib + lfib;
        lfib = fib;
        fib = nfib;
    }

    while (fib - fib2 >= n) {
        int nfib2 = fib2 + lfib2;

        fib -= fib2;

        lfib2 = fib2;
        fib2 = nfib2;
    }

    std::cout << fib << std::endl;

}