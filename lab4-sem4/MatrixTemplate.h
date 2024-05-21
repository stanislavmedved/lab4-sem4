#pragma once
#include <iostream>
#include <fstream>
#include "ExtraConcepts.h"

template<valid_numeric T>
class MatrixTemplate {
protected:
	unsigned int m;
	unsigned int n;
	T** data;
public:
	// Конструктор и деструктор
	MatrixTemplate(unsigned int rows, unsigned int cols);
	~MatrixTemplate();
	// Оператор обращения по индексу
	T* operator[](unsigned int i);
	// Метод заполнения случайными числами
	void fillRandom();
	// Оператор <<
	friend std::ostream& operator<< <>(std::ostream& os, const MatrixTemplate<T>& matrix);
	// Операторы сложения/вычитания/умножения
	MatrixTemplate<T>& operator+=(const MatrixTemplate<T>& other);
	MatrixTemplate<T> operator+(const   MatrixTemplate<T>& other);
	MatrixTemplate<T>& operator-=(const MatrixTemplate<T>& other);
	MatrixTemplate<T> operator-(const   MatrixTemplate<T>& other);
	MatrixTemplate<T> operator*(const   MatrixTemplate<T>& other);
	// Операторы сравнения
	bool operator!=(const MatrixTemplate<T>& other) const;
	bool operator==(const MatrixTemplate<T>& other) const;
};