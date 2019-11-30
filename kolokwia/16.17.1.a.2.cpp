//
// Created by Bartłomiej Grzesik on 30/11/2019.
//

#include <cmath>
#include <iostream>

const int MAX = 10121;

struct result
{
    int max[10];
};

result find_max(int t[MAX])
{
    result r;
    for (int i = 0; i < 10; r.max[i++] = 0);

    int counter[1001];
    for (int i = 0; i < 1001; counter[i++] = 0);

    for (int i = 0; i < MAX; ++i) {
        counter[t[i]]++;
    }

    int c = 9;
    for (int i = 1000; i >= 0 && c >= 0; --i) {
        if (counter[i] == 0) continue;
        counter[i]--;
        r.max[c] = i;
        c--;
        i--;
    }

    return r;
}

int main(int argc, char *argv[])
{
    srand(time(NULL));

    int t[MAX];
    for (int i = 0; i < MAX; ++i) {
        t[i] = rand() % 1000 + 1;
    }

    result result = find_max(t);

    for (int i = 0; i < 10; ++i) {
        std::cout << result.max[i] << std::endl;
    }
}