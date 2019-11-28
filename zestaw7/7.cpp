//
// Created by Bartłomiej Grzesik on 28/11/2019.
//

#include <cstring>
#include <iostream>

const int N = 6;

bool recur(const int tab[N], int size, int indexSum, int i, int *elemSum)
{
    if (size == 0) {
        return indexSum != 0 && indexSum == *elemSum;
    }
    if (i >= N) {
        return false;
    }

    if (recur(tab, size, indexSum, i + 1, elemSum)) {
        return true;
    }

    *elemSum += tab[i];
    if (recur(tab, size - 1, indexSum + i, i + 1, elemSum)) {
        return true;
    }
    *elemSum -= tab[i];

    return false;

}

int findSmallest(const int tab[N])
{
    int smallest = 0;

    for (int i = 2; i < N; ++i) {
        if (recur(tab, i, 0, 0, &smallest)) {
            break;
        }
    }

    return smallest;
}


int main(int argc, const char *argv[])
{
    //           0  1  2  3   4  5
    int t[N] = { 1, 7, 3, 5, 11, 2 };

    std::cout << findSmallest(t) << std::endl;
}