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

template<int N>
bool mozna_odwazyc(int wagi[N], int s, int i = 0)
{
    if (s == 0) {
        return true;
    }
    if (i == N) {
        return false;
    }

    if (mozna_odwazyc<N>(wagi, s, i + 1)) {
        return true;
    }

    if (mozna_odwazyc<N>(wagi, s - wagi[i], i + 1)) {
        std::cout << "po lewej " << wagi[i] << std::endl;
        return true;
    }

    if (mozna_odwazyc<N>(wagi, s + wagi[i], i + 1)) {
        std::cout << "po prawej " << wagi[i] << std::endl;
        return true;
    }

    return false;
}


int main()
{
    int wagi[] = { 6, 7, 3 };

    std::cout << mozna_odwazyc<sizeof(wagi) / sizeof(int)>(wagi, 4) << std::endl;
}
