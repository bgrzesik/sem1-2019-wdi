//
// Created by Bartłomiej Grzesik on 2019-05-13.
//

#include <iostream>
#include <iterator>
#include <random>
#include <algorithm>


void BubbleSort(int arr[], size_t n)
{
    for (size_t i = 0; i < n - 1; i++) {
        for (size_t j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}


void SelectionSort(int arr[], size_t n)
{
    for (size_t i = 0; i < n - 1; i++) {
        size_t min = i;
        for (size_t j = i + 1; j < n; ++j) {
            if (arr[min] > arr[j]) {
                min = j;
            }
        }

        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

void InsertSort(int arr[], size_t n)
{
    for (size_t i = 1; i < n; ++i) {
        int val = arr[i];
        int j = i - 1;

        while (j >= 0 && val < arr[j]) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = val;
    }
}

int main(int argc, const char *argv[])
{
    int arr[] = { 32, 52, 12, 55, 42, 100, 2, -1 };
    std::random_device rd;
    std::shuffle(std::begin(arr), std::end(arr), rd);


    std::copy(std::begin(arr), std::end(arr), std::ostream_iterator<int>(std::cout, "\t"));
    std::cout << std::endl << std::flush;

    BubbleSort(arr, std::size(arr));

    std::copy(std::begin(arr), std::end(arr), std::ostream_iterator<int>(std::cout, "\t"));
    std::cout << std::endl << std::flush;

    std::shuffle(std::begin(arr), std::end(arr), rd);

    std::copy(std::begin(arr), std::end(arr), std::ostream_iterator<int>(std::cout, "\t"));
    std::cout << std::endl << std::flush;

    SelectionSort(arr, std::size(arr));

    std::copy(std::begin(arr), std::end(arr), std::ostream_iterator<int>(std::cout, "\t"));
    std::cout << std::endl << std::flush;

    std::shuffle(std::begin(arr), std::end(arr), rd);

    std::copy(std::begin(arr), std::end(arr), std::ostream_iterator<int>(std::cout, "\t"));
    std::cout << std::endl << std::flush;

    InsertSort(arr, std::size(arr));

    std::copy(std::begin(arr), std::end(arr), std::ostream_iterator<int>(std::cout, "\t"));
    std::cout << std::endl << std::flush;


    return 0;
}