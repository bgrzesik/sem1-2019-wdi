//
// Created by Bartłomiej Grzesik on 24/10/2019.
//

#include <iostream>
#include <cmath>

// 6. Proszę napisać program,który wczytuje wprowadzany z klawiatury ciąg liczb naturalnych
// zakończonych zerem stanowiącym wyłącznie znacznik końca danych.
// Program powinien wypisać 10 co do wielkości wartość, jaka wystąpiła w ciągu.
// Można założyć, że w ciągu znajduje się wystarczająca liczba elementów.

int top[10];

int main()
{
    const int input[] = { 23, 232, 1, 35, 65, 567, 7565, 65, 32, 12, 53, 35, 46, 453, 123, 21, 12, 1, 3, 55, 1 };

    for (const int &in : input) {
        int i = 10;
        while (--i >= 0 && top[i] > in);

        if (i <= -1) {
            continue;
        }

        for (int j = 0; j < i; ++j) {
            top[j] = top[j + 1];
        }

        top[i] = in;
    }

    for (int i : top) {
        std::cout << i << ", ";
    }
    std::cout << std::endl;
}