#include <iostream>

//
// Created by Bartłomiej Grzesik on 18/11/2019.
//


/*
 1. Dany jest zestaw odważników int t[N]. Napisać funkcję,
 która sprawdza czy jest możliwe odważenie określonej masy.
 Odważniki można umieszczać tylko na jednej szalce.
 */

bool mozna_odwazyc(int wagi[], int n, int s, int i = 0, int sum = 0)
{
    if (i + 1 == n) {
        return sum == s || sum + wagi[i] == s;
    }

    return mozna_odwazyc(wagi, n, s, i + 1, sum) || mozna_odwazyc(wagi, n, s, i + 1, sum + wagi[i]);
}


int main()
{
    int wagi[] = { 2, 2, 3, 4, 5, 6, 6 };

    std::cout << mozna_odwazyc(wagi, sizeof(wagi) / sizeof(int), 7) << std::endl;
}
