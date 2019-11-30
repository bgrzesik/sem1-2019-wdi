//
// Created by Bartłomiej Grzesik on 30/11/2019.
//

#include <cmath>
#include <iostream>

struct tower_alloc
{
    int tower1_x;
    int tower1_y;

    int tower2_x;
    int tower2_y;
};

tower_alloc alloc_towers(int t[8][8])
{
    int cols[8];
    int rows[8];

    for (int i = 0; i < 8; cols[i] = rows[i] = 0, i++);

    for (int y = 0; y < 8; ++y) {
        for (int x = 0; x < 8; ++x) {
            cols[y] += t[y][x];
            rows[x] += t[y][x];
        }
    }

    int vals[8][8];

    for (int y = 0; y < 8; ++y) {
        for (int x = 0; x < 8; ++x) {
            vals[y][x] = cols[x] + rows[y] - 2 * t[y][x];
        }
    }


    int col1 = 0;
    int row1 = 0;

    for (int y = 0; y < 8; ++y) {
        for (int x = 0; x < 8; ++x) {
            if (vals[y][x] > vals[row1][col1]) {
                col1 = x;
                row1 = y;
            }
        }
    }

    int col2 = col1 == 0 ? 1 : 0;
    int row2 = row1 == 0 ? 1 : 0;

    for (int y = 0; y < 8; ++y) {
        for (int x = 0; x < 8; ++x) {
            if (y == row1 or x == col1) continue;

            if (vals[y][x] > vals[row2][col2]) {
                col2 = x;
                row2 = y;
            }
        }
    }


    tower_alloc alloc;
    alloc.tower1_x = col1;
    alloc.tower1_y = row1;
    alloc.tower2_x = col2;
    alloc.tower2_y = row2;

    return alloc;
}


int main(int argc, char *argv[])
{
    int chessboard[8][8] = {
        { 1, 2, 3, 4, 4, 3, 2, 1 },
        { 2, 3, 4, 5, 5, 4, 3, 2 },
        { 3, 4, 5, 6, 6, 5, 4, 3 },
        { 4, 5, 6, 7, 7, 6, 5, 4 },

        { 4, 5, 6, 7, 7, 6, 5, 4 },
        { 3, 4, 5, 6, 6, 5, 4, 3 },
        { 2, 3, 4, 5, 5, 4, 3, 2 },
        { 1, 2, 3, 4, 4, 3, 2, 1 },
    };

    tower_alloc alloc = alloc_towers(chessboard);
    printf("%d %d\n", alloc.tower1_x, alloc.tower1_y);
    printf("%d %d\n", alloc.tower2_x, alloc.tower2_y);
}