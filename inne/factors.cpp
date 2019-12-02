//
// Created by Bartłomiej Grzesik on 01/12/2019.
//

#include <iostream>

const int MAX = 100;

int min(int a, int b)
{
    if (a < b) {
        return a;
    } else {
        return b;
    }
}

int _print_factors(int factors[MAX], int idx, int left, int max)
{
    if (left == 0) {
        std::cout << factors[0];
        for (int i = 1; i < idx; ++i) {
            std::cout << " + " << factors[i];
        }
        std::cout << " + 1" << std::endl;
        return 1;
    }

    int sum = 0;
    for (int i = min(left, max); i >= 1; --i) {
        factors[idx] = i;
        _print_factors(factors, idx + 1, left - i, i);
    }
    return sum;
}

int print_factors(int n)
{
    int factors[MAX];
    return _print_factors(factors, 0, n, n);
}


int main(int argc, const char *argv[])
{
    print_factors(5);
}