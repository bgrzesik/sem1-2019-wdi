//
// Created by Bartłomiej Grzesik on 11/11/2019.
//
#ifndef WDI_ULAMKI_HPP
#define WDI_ULAMKI_HPP


struct ulamek
{
    int l;
    int m;
};

int nwd(int a, int b)
{
    a = abs(a);
    b = abs(b);

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
    int d = nwd(abs(u.l), abs(u.m));

    if (u.l < 0 && u.m < 0) {
        u.l = -u.l;
        u.m = -u.m;
    }

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
    return skroc(u);
}

ulamek iloraz(ulamek a, ulamek b)
{
    ulamek u;
    u.l = a.l * b.m;
    u.m = b.l * a.m;
    return skroc(u);
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

#endif //WDI_ULAMKI_HPP
