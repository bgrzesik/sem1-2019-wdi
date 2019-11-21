#include <iostream>

//
// Created by Bartłomiej Grzesik on 18/11/2019.
//


/*
 4. „Waga” liczby jest określona jako ilość różnych czynników pierwszych liczby.
 Na przykład waga(1)=0, waga(2)=1, waga(6)=2, waga(30)=3, waga(64)=1.
 Dana jest tablica: int t[N]. Tablica zawiera liczby naturalne.
 Proszę napisać funkcję, która sprawdza czy można elementy tablicy podzielić na 3 podzbiory o równych wagach.
 Do funkcji należy przekazać wyłącznie tablicę, funkcja powinna zwrócić wartość typu bool.
*/

int waga(int n, int d)
{
    if (n <= 1) {
        return 0;
    }

    int r = 0;

    if (n % d == 0) {
        r = 1;
        do {
            n /= d;
        } while (n % d == 0);
    }

    if (n <= 1) {
        return r;
    }

    while (n % d != 0) {
        d++;
    }

    return r + waga(n, d);
}

bool recur(int wagi[], int n, int i, int p1, int p2, int p3)
{
    if (n == i) {
        return p1 == p2 && p2 == p3;
    }

    return recur(wagi, n, i + 1, p1 + wagi[i], p2, p3) ||
           recur(wagi, n, i + 1, p1, p2 + wagi[i], p3) ||
           recur(wagi, n, i + 1, p1, p2, p3 + wagi[i]);
}

template<int n>
bool mozna(int t[n])
{
    int wagi[n];
    int sum = 0;

    for (int i = 0; i < n; ++i) {
        sum += wagi[i] = waga(n, 2);
    }

    return recur(wagi, n, 0, 0, 0, 0);
}


int main()
{
    std::cout << "waga(1) = " << waga(1, 2) << " (=0)" << std::endl;
    std::cout << "waga(2) = " << waga(2, 2) << " (=1)" << std::endl;
    std::cout << "waga(6) = " << waga(6, 2) << " (=2)" << std::endl;
    std::cout << "waga(30) = " << waga(30, 2) << " (=3)" << std::endl;
    std::cout << "waga(64) = " << waga(64, 2) << " (=1)" << std::endl;

    int liczby[] = { 3 * 11, 3 * 5, 7 * 2, 2, 7, 4, 0 };
    std::cout << mozna<6>(liczby) << std::endl;
    //int liczby2[] = { 2, 6, 30, 64, 1 };
    std::cout << mozna<7>(liczby) << std::endl;
}
