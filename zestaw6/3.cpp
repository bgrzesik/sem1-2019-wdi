#include <iostream>

//
// Created by Bartłomiej Grzesik on 18/11/2019.
//


/*
 1. Dany jest zestaw odważników int t[N]. Napisać funkcję,
 która sprawdza czy jest możliwe odważenie określonej masy.
 Odważniki można umieszczać tylko na jednej szalce.

 2. Poprzednie zadanie, odważniki można umieszczać na obu szalkach.

 3. Poprzednie zadanie. Program powinien wypisywać wybrane odważniki.

 */

bool mozna_odwazyc(int wagi[], int n, int s, int i = 0)
{
    if (s == 0) {
        return true;
    }
    if (i == n) {
        return false;
    }

    if (mozna_odwazyc(wagi, n, s, i + 1)) {
        return true;
    }

    if (mozna_odwazyc(wagi, n, s - wagi[i], i + 1)) {
        std::cout << "po lewej " << wagi[i] << std::endl;
        return true;
    }

    if (mozna_odwazyc(wagi, n, s + wagi[i], i + 1)) {
        std::cout << "po prawej " << wagi[i] << std::endl;
        return true;
    }

    return false;
}


int main()
{
    int wagi[] = { 6, 7, 3 };

    std::cout << mozna_odwazyc(wagi, sizeof(wagi) / sizeof(int), 4) << std::endl;
}
