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

int waga(int n)
{

    if (n == 0) {
        return 0;
    }
    int dzielnik = 2;

    int c = n % 2 == 0 ? 1 : 0;

    while (n != 1) {
        while (n % dzielnik == 0) {
            n /= dzielnik;
        }

        if (n == 1) {
            break;
        }

        while (n % dzielnik != 0) {
            dzielnik++;
        }

        c++;
    }

    return c;
}

bool mozna(int t[], int n)
{
    int wagi[3] = { 0, 0, 0 };
    int i_waga = 0;

    for (int i = 1; i < n; ++i) {
        int c_waga = waga(t[i]);

        int w = 0;
        while (wagi[w] != c_waga) {
            if (w == 3) {
                return false;
            }

            if (w == i_waga) {
                wagi[w] = c_waga;
                i_waga++;
                break;
            }

            w++;
        }
    }
    return true;
}


int main()
{
    std::cout << "waga(1) = " << waga(1) << " (=0)" << std::endl;
    std::cout << "waga(2) = " << waga(2) << " (=1)" << std::endl;
    std::cout << "waga(6) = " << waga(6) << " (=2)" << std::endl;
    std::cout << "waga(30) = " << waga(30) << " (=3)" << std::endl;
    std::cout << "waga(64) = " << waga(64) << " (=1)" << std::endl;

    int liczby[] = { 2, 6, 30, 64 };
    std::cout << mozna(liczby, 4) << std::endl;
    int liczby2[] = { 2, 6, 30, 64, 1 };
    std::cout << mozna(liczby2, 5) << std::endl;
}
