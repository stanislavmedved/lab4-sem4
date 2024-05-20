﻿#include <iostream>
#include <concepts>
#include <type_traits>
#include "ExtraConcepts.h"

template<valid_second_max T>
int findSecondMaxIndex(T *arr, unsigned int size) {
    T maxElement = arr[0];
    //find max index
    for (int i = 0; i < size; i++) {
        if (arr[i] > maxElement) {
            maxElement = arr[i];
        }
    }
    T secondMax = arr[0];
    int resultIndex = 0;
    // find second max
    for (int i = 0; i < size; i++) {
        if (arr[i] > secondMax && arr[i] != maxElement) {
            resultIndex = i;
            secondMax = arr[i];
        }
    }
    return resultIndex;
}

int main()
{
    std::cout << "Hello World!\n";
}