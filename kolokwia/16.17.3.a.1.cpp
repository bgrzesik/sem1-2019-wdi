//
// Created by Bartłomiej Grzesik on 30/11/2019.
//

#include <cmath>
#include <iostream>

const int N = 3;

bool are_friends(int a[10], int b[10])
{
    int c = 0;

    for (int i = 0; i < 10; ++i) {
        if (a[i] != 0 && b[i] != 0) {
            c++;
            if (c >= 2) {
                return true;
            }
        }
    }

    return false;
}

int remove_lonelies(int t[N][N])
{
    int tt[N][N][10];
    memset(tt, 0, sizeof(tt));

    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < N; ++x) {
            int a = t[y][x];

            while (a > 0) {
                tt[y][x][a % 10]++;
                a /= 10;
            }
        }
    }

    int count = 0;

    for (int i = 0; i < N * N - 1; ++i) {
        bool has_friends = false;

        for (int j = i; j < N * N; ++j) {
            if (are_friends(tt[i / 10][i % 10], tt[j / 10][j % 10])) {
                has_friends = true;
                break;
            }
        }

        if (has_friends) {
            count++;
        } else {
            t[i / 10][i % 10] = 0;
        }
    }

    return count;
}


int main(int argc, char *argv[])
{
    int tab[3][3] = {
        { 120, 464, 201 },
        { 765, 435, 222 },
        { 120, 464, 891 },
    };

    std::cout << remove_lonelies(tab) << std::endl;

}