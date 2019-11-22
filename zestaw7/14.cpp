//
// Created by Bartłomiej Grzesik on 22/11/2019.
//

#include <cstring>
#include <iostream>

struct pos
{
    int x;
    int y;
};

template<int N>
struct queens
{
    bool columns[N];
    bool rows[N];

    pos queens[N];
};

int abs(int a)
{
    return a < 0 ? -a : a;
}

template<int N>
bool alloc_queens(queens<N> &board, int i)
{
    if (i == N) {
        return true;
    }

    for (int x = 0; x < N; ++x) {
        if (board.columns[x]) continue;

        board.columns[x] = true;

        for (int y = 0; y < N; ++y) {
            if (board.rows[y]) continue;

            board.rows[y] = true;


            bool beats = false;
            for (int j = 0; j < N; ++j) {
                pos &q = board.queens[j];

                if (abs(q.x - x) == abs(q.y - y)) {
                    beats = true;
                    break;
                }
            }

            if (beats) {
                board.rows[y] = false;
                continue;
            }

            board.queens[i].x = x;
            board.queens[i].y = y;

            if (alloc_queens(board, i + 1)) {
                std::cout << "(" << x << ", " << y << ")" << std::endl;
                return true;
            }

            board.rows[y] = false;
        }

        board.columns[x] = false;
    }

    return false;
}

int main()
{
    queens<8> board;

    memset(&board, 0, sizeof(board));

    alloc_queens(board, 0);
}

