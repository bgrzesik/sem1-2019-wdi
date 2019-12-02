//
// Created by Bartłomiej Grzesik on 30/11/2019.
//



#include <iostream>

template<int N>
int det(int mat[N][N], bool col[N], bool row[N], int n = N)
{
    if (n == 1) {
        int x = 0;
        int y = 0;

        while (x < N && col[x]) { x++; }
        while (y < N && row[y]) { y++; }

        if (x >= N || y >= N) {
            throw 10;
        }

        return mat[y][x];
    }

    int sum = 0;
    int y = 0;
    while (y < N && row[y]) { y++; }

    row[y] = true;

    int ix = 0;

    for (int x = 0; x < N; x++) {
        if (col[x]) continue;

        ix++;

        col[x] = true;

        int minor = det<N>(mat, col, row, n - 1);
        if (ix % 2 == 1) {
            sum += mat[y][x] * minor;
        } else {
            sum -= mat[y][x] * minor;
        }


        col[x] = false;
    }
    row[y] = false;


    return sum;
}

int main()
{
    int mat2[2][2] = {
        { 1, 1 },
        { 1, 1 }
    };

    bool col2[2] { false, false };
    bool row2[2] { false, false };

    std::cout << det<2>(mat2, col2, row2) << std::endl;


    int mat3[3][3] = {
        { 1, 0, 0 },
        { 0, 1, 0 },
        { 0, 0, 1 },
    };

    bool col3[3] { false, false, false };
    bool row3[3] { false, false, false };

    std::cout << det<3>(mat3, col3, row3) << std::endl;

    {
        int mat4[4][4] = {
            { 1, 0, 0, 0 },
            { 0, 1, 0, 0 },
            { 0, 0, 1, 0 },
            { 0, 0, 0, 1 },
        };

        bool col4[4] { false, false, false, false };
        bool row4[4] { false, false, false, false };

        std::cout << det<4>(mat4, col4, row4) << std::endl;
    }
    {
        int mat4[4][4] = {
            { 1, 3, 5, 9 },
            { 1, 3, 1, 7 },
            { 4, 3, 9, 7 },
            { 5, 2, 0, 9 },
        };

        bool col4[4] { false, false, false, false };
        bool row4[4] { false, false, false, false };

        std::cout << det<4>(mat4, col4, row4) << std::endl;
    }
}
