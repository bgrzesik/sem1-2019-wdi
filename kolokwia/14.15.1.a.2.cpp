//
// Created by Bartłomiej Grzesik on 01/12/2019.
//

#include <iostream>

const int N = 5;

void sort(int t1[N][N], int t2[N * N])
{
    int indexes[N];
    for (int i = 0; i < N; indexes[i++] = 0);

    for (int i = 0; i < N * N; ++i) {
        int idx = 0;

        while (indexes[idx] >= N) {
            idx++;
        }

        int min = t1[idx][indexes[idx]];

        for (int i = idx; i < N; ++i) {
            if (indexes[idx] >= N) {
                continue;
            }
            if (t1[idx][indexes[idx]] >= t1[i][indexes[i]]) {
                idx = i;
            }
        }

        indexes[idx]++;
        t2[i] = min;
    }
}

int main(int argc, const char *argv[])
{
    int t1[N][N] = {
        { 1,  1,  3,  8,  9 },
        { 2,  3,  4,  5,  10 },
        { 6,  8,  9,  11, 14 },
        { 11, 13, 14, 15, 16 },
        { 17, 19, 20, 22, 24 },
    };

    int t2[N * N];

    sort(t1, t2);
}