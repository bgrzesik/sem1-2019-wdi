//
// Created by Bartłomiej Grzesik on 24/10/2019.
//

#include <iostream>

// 2. Znaleźć wyrazy początkowe zamiast 1,1 o najmniejszej sumie, aby w ciągu analogicznym
// do ciągu Fibonacciego wystąpił wyraz równy numerowi bieżącego roku.

int main() {

    int a = 0;
    while (true) {
        int n = ++a;
        int l = n;

        while (n <= 2019) {

            if (n == 2019) {
                std::cout << n << " " << a << std::endl;
                return 0;
            }

            int t = n + l;
            l = n;
            n = t;
        }

        if (a > 2019) {
            break;
        }
    }


}