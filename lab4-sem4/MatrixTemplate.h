#pragma once
#include <iostream>
#include "ExtraConcepts.h"

template<valid_numeric T>
class MatrixTemplate {
private:
	unsigned int m;
	unsigned int n;
	T** data;

public:
	// ����������� � ����������
	MatrixTemplate<T>(unsigned int rows, unsigned int cols);
	~MatrixTemplate();
	// �������� ��������� �� �������
	T* operator[](unsigned int i);
	// ����� ���������� ���������� �������
	void fillRandom();
	// �������� <<
	friend std::ostream& operator<<(std::ostream& os, const MatrixTemplate<T>& matrix);
	// ��������� ��������/���������/���������
	MatrixTemplate<T>& operator+=(const MatrixTemplate<T>& other);
	MatrixTemplate<T> operator+(const   MatrixTemplate<T>& other);
	MatrixTemplate<T>& operator-=(const MatrixTemplate<T>& other);
	MatrixTemplate<T> operator-(const   MatrixTemplate<T>& other);
	MatrixTemplate<T> operator*(const   MatrixTemplate<T>& other);
	// ��������� ���������
	bool operator!=(const MatrixTemplate<T>& other) const;
	bool operator==(const MatrixTemplate<T>& other) const;
};
