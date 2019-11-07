//
// Created by Bartłomiej Grzesik on 03/11/2019.
//

#include <iostream>

/*
1. Dana jest tablica int t[MAX][MAX].Prosze napisać funkcję wypełniającą tablicę liczbami naturalnymi po spirali.
 */


#define MAX 20

int tab[MAX][MAX];

int main()
{
    int x = 0;
    int y = 0;
    int a = 1;

    for (x = 0; x < MAX; ++x) {
        tab[y][x] = a++;
    }


    for (int i = 1; i <= MAX / 2; ++i) {
        x--;
        y++;
        for (int yy = 0; yy < MAX - i * 2 + 1; ++yy, ++y)
            tab[y][x] = a++;

        y--;
        x--;
        for (int xx = 0; xx < MAX - i * 2 + 1; ++xx, --x)
            tab[y][x] = a++;

        x++;
        y--;
        for (int yy = 0; yy < MAX - i * 2; ++yy, --y)
            tab[y][x] = a++;

        y++;
        x++;
        for (int xx = 0; xx < MAX - i * 2; ++xx, ++x)
            tab[y][x] = a++;

        std::cout << MAX - i * 2 << " " << MAX - i * 2 + 1 << std::endl;
    }

    for (int xx = 0; xx < MAX; ++xx) {
        for (int yy = 0; yy < MAX; ++yy) {
            std::cout << tab[xx][yy] << "\t";
        }
        std::cout << std::endl;
    }

}