//
// Created by Bartłomiej Grzesik on 02/12/2019.
//

#include <iostream>
#include <cmath>

const int N = 5;

bool is_prime(int a)
{
    for (int i = 2; i < sqrt(a) + 1; ++i) {
        if (a % i == 0) {
            return false;
        }
    }
    return true;
}

int main()
{
    const int N = 5;
    int t[N][N] = {
        { 1,  6,  6,  4,  3, },
        { 1,  7,  13, 19, 3, },
        { 1,  2,  3,  4,  3, },
        { 0,  2,  4,  6,  8, },
        { 11, 61, 63, 41, 32, },
    };

    int len = 0;
    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < N - 1;) {
            if (not is_prime(t[y][x]) or not is_prime(t[y][x + 1])) {
                x++;
                continue;
            }

            int a = t[y][x + 1] - t[y][x];
            int clen = 1;

            while (t[y][x + 1] - t[y][x] == a and x < N - 1 and is_prime(t[y][x]) and is_prime(t[y][x + 1])) {
                x++;
                clen++;
            }

            if (clen > len) {
                len = clen;
            }
        }
    }

    std::cout << len << std::endl;
}