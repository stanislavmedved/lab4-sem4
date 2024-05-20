#include <iostream>
#include <concepts>
#include <type_traits>
#include <vector>
#include "ExtraConcepts.h"
#include "MatrixTemplate.h"

template<valid_second_max T>
// второй максимум
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
template<valid_second_max T>
void printVector(std::vector<T>& arr) {
    for (auto x : arr) {
        std::cout << x << ' ';
    }
}
template<valid_second_max T>
void testSecondMaxWithVector(std::vector<T>& arr) {
    std::cout << "Индекс второго максимума для массива "; printVector(arr); std::cout << ": " << findSecondMaxIndex(arr.data(), arr.size());
}
void secondMaxUnitTest() {
    std::vector<int> testInts = { 1,2,3,4,5 };
    std::vector<float>  testFloats  = { 1.2f, 2.3f, 3.4f, 4.5f, 5.6f };
    std::vector<double> testDoubles = { 1.2,2.3,3.4,4.5,5.6 };
    std::vector<char>   testChar    = { 'a','b','c','d','e' };

    testSecondMaxWithVector(testInts);
    testSecondMaxWithVector(testFloats);
    testSecondMaxWithVector(testDoubles);
    testSecondMaxWithVector(testChar);

}
// шаблонные матрицы
template<valid_numeric T>
void testTwoMatrices(MatrixTemplate<T>& matrix1, MatrixTemplate<T>& matrix2) {
    // Заполняем матрицы случайными числами
    matrix1.fillRandom();
    matrix2.fillRandom();

    // Выводим их на экран
    std::cout << "Матрица 1:\n" << matrix1 << std::endl;
    std::cout << "Матрица 2:\n" << matrix2 << std::endl;

    // Сложение матриц
    Matrix resultAdd = matrix1 + matrix2;
    std::cout << "Сумма матриц:\n" << resultAdd << std::endl;

    // Вычитание матриц
    Matrix resultSubtract = matrix1 - matrix2;
    std::cout << "Разность матриц:\n" << resultSubtract << std::endl;

    // Умножение матриц
    Matrix resultMultiply = matrix1 * matrix2;
    std::cout << "Произведение матриц:\n" << resultMultiply << std::endl;

    // Проверка на равенство и неравенство матриц
    if (matrix1 == matrix2) {
        std::cout << "Матрицы равны.\n";
    }
    else {
        std::cout << "Матрицы не равны.\n";
    }

    if (matrix1 != matrix2) {
        std::cout << "Матрицы не равны.\n";
    }
    else {
        std::cout << "Матрицы равны.\n";
    }

}
void matrixTemplateUnitTest() {
    MatrixTemplate<int> intMatrix1 = MatrixTemplate<int>(3, 3);
    MatrixTemplate<int> intMatrix2 = MatrixTemplate<int>(3, 3);
    testTwoMatrices(intMatrix1, intMatrix2);
    MatrixTemplate<float> floatMatrix1 = MatrixTemplate<float>(3, 3);
    MatrixTemplate<float> floatMatrix2 = MatrixTemplate<float>(3, 3);
    testTwoMatrices(floatMatrix1, floatMatrix2);
    MatrixTemplate<double> doubleMatrix1 = MatrixTemplate<double>(3, 3);
    MatrixTemplate<double> doubleMatrix2 = MatrixTemplate<double>(3, 3);
    testTwoMatrices(doubleMatrix1, doubleMatrix2);
}

int main()
{
    setlocale(LC_ALL, "rus");
    secondMaxUnitTest();
    matrixTemplateUnitTest();
}