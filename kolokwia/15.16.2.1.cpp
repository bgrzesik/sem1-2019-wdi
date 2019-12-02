//
// Created by Bartłomiej Grzesik on 30/11/2019.
//

#include <cmath>
#include <iostream>

const int N = 3;

bool is_fib(int n)
{
    int l = 1;
    int a = 1;

    while (a <= n) {
        if (a == n) {
            return true;
        }
        int b = a;
        a = a + l;
        l = b;
    }
    return false;
}

int find_fib(int t[N][N])
{
    int row = -1;
    int len = 0;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N - 2; ++j) {
            int a = t[i][j];
            int b = t[i][j + 1];
            int c = t[i][j + 2];

            if (not is_fib(a) or not is_fib(b) or not is_fib(c)) {
                continue;
            }

            int l = 3;

            for (int k = j + 3; k < N; ++k) {
                if (b + c != t[i][k]) continue;

                b = c;
                c = t[i][k];
                l++;
            }

            if (l > len) {
                row = i;
                len = l;
            }
        }
    }

    return row;
}

int main(int argc, char *argv[])
{
    int t[N][N] = {
        { 1,  3,  4 },
        { 34, 55, 89 },
        { 5,  1,  5 },
    };

    std::cout << find_fib(t) << std::endl;
}