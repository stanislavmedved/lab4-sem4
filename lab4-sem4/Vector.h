#pragma once
#include "MatrixTemplate.h"

template<valid_numeric T>
class Vector : public MatrixTemplate<T> {
public:
	using MatrixTemplate<T>::m;
	using MatrixTemplate<T>::n;
	using MatrixTemplate<T>::data;
	Vector(unsigned int size);
	Vector<T> crossProduct(const Vector<T>& other);
	T dotProduct(const Vector<T>& other);

	T operator[](unsigned int i);
};