#pragma once
#include "MatrixTemplate.h"
template<valid_numeric T>
class Vector : public MatrixTemplate<T> {
public:
	Vector(unsigned int size);
	Vector<T> crossProduct(const Vector<T>& other);
	T dotProduct(const Vector<T>& other);
};