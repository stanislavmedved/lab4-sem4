#pragma once
#include "Vector.h"

template<valid_numeric T>
Vector<T>::Vector(unsigned int size) : MatrixTemplate<T>(1, size) {}

template<valid_numeric T>
Vector<T> Vector<T>::crossProduct(const Vector<T>& other)
{
	if (this->n != other.n) {
		throw std::invalid_argument("–азмеры векторов не совпадают!");
	}
	if (this->n != 3) {
		throw std::invalid_argument("Ќевозможно вычислить векторное произведение!");
	}
	Vector<T> result(this->n);
	result.data[0][0] = this->data[0][1] * other.data[0][2] - this->data[0][2] * other.data[0][1];
	result.data[0][1] = (this->data[0][0] * other.data[0][2] - this->data[0][2] * other.data[0][0]);
	result.data[0][2] = this->data[0][0] * other.data[0][1] - this->data[0][1] * other.data[0][0];
	return result;
}

template<valid_numeric T>
T Vector<T>::dotProduct(const Vector<T>& other)
{
	if (this->n != other.n) {
		throw std::invalid_argument("–азмеры векторов не совпадают!");
	}
	T result = static_cast<T>(0);
	for (int i = 0; i < this->n; i++) {
		result += this->data[0][i] * other.data[0][i];
	}
	return result;
}

template<valid_numeric T>
T Vector<T>::operator[](unsigned int i)
{
	return this->data[0][i];
}
