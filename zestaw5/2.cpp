//
// Created by Bartłomiej Grzesik on 10/11/2019.
//


#include <iostream>

struct ulamek
{
    int l;
    int m;
};

int nwd(int a, int b)
{
    while (a != b && a != 0 && b != 0) {
        if (a > b) {
            a -= b;
        } else {
            b -= a;
        }
    }
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

ulamek skroc(ulamek u)
{
    int d = nwd(u.l, u.m);

    u.l /= d;
    u.m /= d;

    return u;
}

ulamek suma(ulamek a, ulamek b)
{
    ulamek u;
    u.l = a.l * b.m + b.l * a.m;
    u.m = a.m * b.m;
    return skroc(u);
}

ulamek roznica(ulamek a, ulamek b)
{
    ulamek u;
    u.l = a.l * b.m - b.l * a.m;
    u.m = a.m * b.m;
    return skroc(u);
}

ulamek iloczyn(ulamek a, ulamek b)
{
    ulamek u;
    u.l = a.l * b.l;
    u.m = a.m * b.m;
    return u;
}

ulamek iloraz(ulamek a, ulamek b)
{
    ulamek u;
    u.l = a.l * b.m;
    u.m = b.l * a.m;
    return u;
}

ulamek wczytaj()
{
    ulamek u;
    std::cin >> u.l >> u.m;
    return u;
}

void wypisz(ulamek u)
{
    std::cout << "( " << u.l << " / " << u.m << " )";
}

ulamek potega(ulamek u, int n)
{
    ulamek a;

    a.l = 1;
    a.m = 1;

    for (int i = 0; i < n; ++i) {
        a.l *= u.l;
        a.m *= u.m;
    }

    return a;
}

struct rownanie
{
    // ax + bx = c
    ulamek a, b, c;
};

ulamek wyznacznik(ulamek a, ulamek b, ulamek c, ulamek d)
{
    // a b
    // c d
    return roznica(iloczyn(a, d), iloczyn(b, c));
}


// gora.a x + gora.b y = gora.c
// dol.a x  + dol.b y  = dol.c
struct uklad
{
    rownanie gora;
    rownanie dol;
};

enum wynik
{
    oznaczone,
    nieoznaczone,
    sprzeczne,
};

wynik rozwiaz_uklad(uklad u, ulamek &x, ulamek &y)
{
    if (u.gora.a.l == 0 && u.gora.b.l == 0 &&
        u.dol.a.l == 0 && u.dol.b.l == 0 &&
        u.gora.c.l != 0 && u.gora.c.l != 0) {

        x = { INT_MAX, INT_MAX };
        y = { INT_MAX, INT_MAX };

        return sprzeczne;
    }

    ulamek w = wyznacznik(u.gora.a, u.gora.b,
                          u.dol.a, u.dol.b);

    ulamek w1 = wyznacznik(u.gora.c, u.gora.b,
                           u.dol.c, u.dol.b);

    ulamek w2 = wyznacznik(u.gora.a, u.gora.c,
                           u.dol.a, u.dol.c);


    if (w.l == 0 && w1.l == 0 && w2.l == 0) {
        x = { INT_MAX, INT_MAX };
        y = { INT_MAX, INT_MAX };

        return nieoznaczone;
    } else if (w.l == 0 && (w1.l != 0 || w2.l != 0)) {
        x = { INT_MAX, INT_MAX };
        y = { INT_MAX, INT_MAX };

        return sprzeczne;
    }

    x = iloraz(w1, w);
    y = iloraz(w2, w);

    return oznaczone;
}

int main()
{
    uklad u = {
        { { 7, 1 }, { 2, 1 }, { 1, 1 } },
        { { 3, 1 }, { 4, 1 }, { 2, 1 } },
    };

    ulamek x, y;

    switch (rozwiaz_uklad(u, x, y)) {
        case oznaczone:
            std::cout << "oznaczone" << std::endl;
            std::cout << "x = ";
            wypisz(x);
            std::cout << std::endl;
            std::cout << "y = ";
            wypisz(y);
            std::cout << std::endl;
            break;

        case nieoznaczone:
            std::cout << "nieoznaczone" << std::endl;
            break;

        case sprzeczne:
            std::cout << "sprzeczne" << std::endl;
            break;

    }


}