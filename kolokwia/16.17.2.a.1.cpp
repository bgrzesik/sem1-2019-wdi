//
// Created by Bartłomiej Grzesik on 30/11/2019.
//

#include <cmath>
#include <iostream>

int nwd(int a, int b)
{
    while (a != b) {
        if (a > b) {
            a -= b;
        }
        if (b > a) {
            b -= a;
        }
    }
    return a;
}

int _gen_semi_prime(int n, int div, int a, int b)
{
    if (div == 0) {
        printf("(%d, %d)", a, b);

        if (a != 0 and b != 0 and nwd(a, b) == 1) {
            printf(" - semi prime\n");
            return 1;
        } else {
            printf("\n");
            return 0;
        }
    }

    int d = (n / div) % 10;
    return _gen_semi_prime(n, div / 10, a * 10 + d, b) +
           _gen_semi_prime(n, div / 10, a, b * 10 + d);
}

int gen_semi_prime(int n)
{
    int div = pow(10, (int) log10(n));
    return _gen_semi_prime(n, div, 0, 0);
}

int main(int argc, char *argv[])
{
    std::cout << gen_semi_prime(21523) << std::endl;
}