//
// Created by Bartłomiej Grzesik on 22/11/2019.
//

#include <cstring>
#include <iostream>

/* 5. Problem skoczka szachowego (treść oczywista) */

constexpr int N = 8;

struct chessboard
{
    int fields[N][N];
};

struct pos
{
    int x;
    int y;
};

void print_chess(chessboard &board)
{
    for (int x = 0; x < N; ++x) {
        std::cout << "\t";
        for (int y = 0; y < N; ++y) {
            std::cout << board.fields[x][y] << "\t";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

bool chess_puzzle(chessboard &board, pos knight, int steps)
{
    pos moves[] = {
        { -1, -2 },
        { +1, -2 },

        { -2, -1 },
        { +2, -1 },

        { -2, +1 },
        { +2, +1 },

        { -1, +2 },
        { +1, +2 },
    };

    if (steps == N * N) {
        for (int x = 0; x < N; ++x) {
            for (int y = 0; y < N; ++y) {
                if (board.fields[x][y] == 0) {
                    return false;
                }
            }
        }

        return true;
    }

    for (int i = 0; i < sizeof(moves) / sizeof(pos); ++i) {
        pos move;
        move.x = moves[i].x + knight.x;
        move.y = moves[i].y + knight.y;

        if (move.x < 0 || move.x >= N) continue;
        if (move.y < 0 || move.y >= N) continue;

        if (board.fields[move.x][move.y] != 0) continue;

        board.fields[move.x][move.y] = steps + 1;
        if (chess_puzzle(board, move, steps + 1)) {
            std::cout << "(" << moves[i].x << " " << moves[i].y << ")"
                      << " to "
                      << "(" << move.x << " " << move.y << ")"
                      << std::endl;

            return true;
        }
        board.fields[move.x][move.y] = 0;
    }

    return false;
}


int main()
{
    chessboard board;
    memset(&board, 0, sizeof(board));

    board.fields[2][2] = 1;

    if (chess_puzzle(board, { 2, 2 }, 1)) {
        print_chess(board);
    }

    return 0;
}