//
// Created by Bartłomiej Grzesik on 02/12/2019.
//

#include <iostream>

const int N = 5;


int main()
{
    int t1[] = { 0, 1, 2, 3, 4 };
    int t2[] = { 0, 1, 2, 3, 4 };

    int l = 0;
    int idx1 = 0;
    int idx2 = 0;

    for (int i = 0; i < N * 2;) {
        if (t1[idx1] < t2[idx2]) {
            idx1++;
            i++;
            continue;
        } else if (t1[idx1] > t2[idx2]) {
            idx2++;
            i++;
            continue;
        }
        int a = t1[idx1];

        while (t1[idx1] == a or t2[idx2] == a) {
            i++;
            l++;

            if (t1[idx1] == a) {
                t1[idx1] = -1;
                idx1++;
            } else {
                t2[idx2] = -1;
                idx2++;
            }
        }
    }
    std::cout << l << std::endl;
    for (int i = 0; i < N; ++i) std::cout << t1[i] << ", ";
    std::cout << std::endl;
    for (int i = 0; i < N; ++i) std::cout << t2[i] << ", ";
    std::cout << std::endl;
}