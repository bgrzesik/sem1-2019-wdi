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

int sum(int wagi[], int szalka[], int n)
{
    int szalka1 = 0;
    int szalka2 = 0;

    for (int i = 0; i < n; ++i) {
        if (szalka[i] == 1) {
            szalka1 += wagi[i];
        }
        if (szalka[i] == 2) {
            szalka2 += wagi[i];
        }
    }

    return szalka1 - szalka2;
}

bool mozna_odwazyc(int wagi[], int szalka[], int n, int s, int i = 0)
{
    if (i == n) {
        return sum(wagi, szalka, n) == s;
    }

    szalka[i] = 0;
    if (mozna_odwazyc(wagi, szalka, n, s, i + 1)) {
        return true;
    }
    szalka[i] = 1;
    if (mozna_odwazyc(wagi, szalka, n, s, i + 1)) {
        return true;
    }
    szalka[i] = 2;
    if (mozna_odwazyc(wagi, szalka, n, s, i + 1)) {
        return true;
    }

    return false;
}


int main()
{
    int wagi[] = { 6, 7, 3 };
    int szalka[] = { 0, 0, 0, 0, 0, 0, 0 };

    std::cout << mozna_odwazyc(wagi, szalka, sizeof(wagi) / sizeof(int), 4) << std::endl;

    std::cout << "L ";
    for (int i = 0; i < sizeof(wagi) / sizeof(int); ++i) {
        if (szalka[i] == 1) {
            std::cout << wagi[i] << " ";
        }
    }
    std::cout << std::endl << "R ";
    for (int i = 0; i < sizeof(wagi) / sizeof(int); ++i) {
        if (szalka[i] == 2) {
            std::cout << wagi[i] << " ";
        }
    }
}
