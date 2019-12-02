//
// Created by Bartłomiej Grzesik on 01/12/2019.
//

#include <iostream>


int main(int argc, const char *argv[])
{
    const int N = 10;

    int t1[10][N] {
        { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 },
        { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 },

        { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 },
        { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 },

        { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 },
        { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 },

        { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 },
        { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 },

        { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 },
        { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 },
    };
    int t2[10 * N];


    int indexes[10];

    for (int i = 0; i < 10; indexes[i++] = 0);
    for (int i = 0; i < 10 * N; t2[i++] = 0);

    int i = 0;
    for (int n = 0; n < 10 * N; ++n) {
        int idx = -1;
        do {
            idx++;
        } while (indexes[idx] >= N);

        for (int m = idx; m < 10; ++m) {
            if (indexes[m] >= 10) continue;
            if (t1[m][indexes[m]] <= t1[idx][indexes[idx]]) {
                idx = m;
            }
        }
        if (i == 0) {
            t2[i] = t1[idx][indexes[idx]];
            i++;
        } else if (t2[i - 1] != t1[idx][indexes[idx]]) {
            t2[i] = t1[idx][indexes[idx]];
            i++;
        }
        indexes[idx]++;
    }

    for (int j = 0; j < i; ++j) {
        printf("%d, ", t2[j]);
    }

}