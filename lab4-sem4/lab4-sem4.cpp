#include <iostream>
#include <concepts>
#include <type_traits>

template<typename T>
concept valid_numeric = std::is_integral<T>::value || std::is_floating_point<T>::value;

template<valid_numeric T>
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
        if (arr[i] > maxElement) {
            resultIndex = i;
            secondMax = arr[i];
        }
    }
}

int main()
{
    std::cout << "Hello World!\n";
}