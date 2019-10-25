//
// Created by Bartłomiej Grzesik on 24/10/2019.
//

#include <iostream>
#include <cmath>

// 8. Napisać program wczytujący trzy liczby naturalne a,b,n i
// wypisujący rozwinięcie dziesiętne ułamka a/b z dokładnością do
// n miejsc po kropce dziesiętnej. (n jest rzędu 100)

int main()
{
    const int a = 1;
    const int b = 13;

    int n = 100;

    std::cout << a / b << ".";

    int r = a % b;
    while (r != 0 && n-- > 0) {
        r *= 10;
        std::cout << r / b;
        r %= b;
    }


}