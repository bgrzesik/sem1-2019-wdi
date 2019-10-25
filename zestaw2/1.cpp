//
// Created by Bartłomiej Grzesik on 25/10/2019.
//

#include <iostream>
#include <cmath>

int main()
{
    const int n = 13 * 21;

    int fib = 1;
    int lfib = 0;

    int fib2;
    int lfib2;

    while (fib < sqrt(n)) {
        int nfib = fib + lfib;
        lfib = fib;
        fib = nfib;

        fib2 = 1;
        lfib2 = 0;

        while (fib2 <= fib) {
            int nfib2 = fib2 + lfib2;
            lfib2 = fib2;
            fib2 = nfib2;

            if (fib2 * fib == n) {
                std::cout << "TAK" << std::endl;
                return 0;
            }
        }
    }

    std::cout << "NIE" << std::endl;
}