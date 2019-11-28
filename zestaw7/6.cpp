//
// Created by Bartłomiej Grzesik on 23/11/2019.
//

#include <iostream>
#include <cmath>


bool is_prime(int n)
{
    for (int i = 2; i < sqrt(n); ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

bool is_possible(int tab[], int n)
{
    if (n == -1) {
        return true;
    }

    int a = tab[--n];

    if (a == 0) {
        return false;
    }

    while (n-- > 0) {
        a <<= 1;
        a |= tab[n];

        if (is_prime(a) && is_possible(tab, n - 1)) {
            std::cout << n << std::endl;
            return true;
        }
    }

    return false;
}

int main()
{

    std::cout << is_prime(13) << std::endl;
    std::cout << is_prime(17) << std::endl;
    std::cout << is_prime(31) << std::endl;

    std::cout << std::endl << std::endl;

    int t1[] = { 1, 1, 1, 0, 1, 1 };

    std::cout << is_possible(t1, 6) << std::endl << std::endl;

    int t2[] = { 1, 1, 0, 1, 0, 0 };

    std::cout << is_possible(t2, 6) << std::endl << std::endl;

    int t3[] = { 1, 0, 1, 1, 0, 1 };

    std::cout << is_possible(t3, 6) << std::endl << std::endl;

    int t4[] = { 1, 1, 1, 1, 1, 1 };

    std::cout << is_possible(t4, 6) << std::endl << std::endl;

}