//
// Created by Bartłomiej Grzesik on 30/11/2019.
//

#include <cmath>
#include <iostream>


struct result
{
    int col1;
    int col2;
};


result which_towers(int t[8][8], int w[8])
{
    result result;
    result.col1 = -1;
    result.col2 = -1;

    int min = INT_MAX;


    for (int x1 = 0; x1 < 7; ++x1) {
        for (int x2 = x1 + 1; x2 < 8; ++x2) {
            bool fields[8][8];
            memset(fields, 0, sizeof(fields));

            for (int x = 0; x < 8; ++x) {
                if (x == x1 || x == x2) continue;

                for (int y = 0; y < 8; ++y) {
                    if (y == w[x]) continue;
                    fields[y][x] |= true;
                }

                for (int c = 0; c < 8; ++c) {
                    if (c == x) continue;
                    fields[w[x]][c] |= true;
                }
            }

            for (int i = 0; i < 8; ++i) {
                fields[w[i]][i] = false;
            }

            int sum = 0;
            for (int r = 0; r < 8; ++r) {
                for (int c = 0; c < 8; ++c) {
                    if (fields[r][c]) {
                        sum += t[r][c];
                    }
                }
            }

            if (sum < min) {
                min = sum;
                result.col1 = x1;
                result.col2 = x2;
            }

        }
    }

    return result;
}


int main(int argc, char *argv[])
{
}