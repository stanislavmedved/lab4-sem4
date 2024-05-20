#include "Vector.h"

template<valid_numeric T>
Vector<T>::Vector(unsigned int size) : MatrixTemplate{1, size} {
}

template<valid_numeric T>
Vector<T> Vector<T>::crossProduct(const Vector<T>& other)
{
	if (this->n != other.n) {
		throw std::invalid_argument("–азмеры векторов не совпадают!");
	}
	if (this->n < 3) {
		throw std::invalid_argument("Ќевозможно вычислить векторное произведение!");
	}
	Vector<T> result(this->n);
	for (int i = 0; i < n; ++i) {
		result[i] = 0;
		for (int j = 0; j < n; ++j) {
			if (i == j) {
				continue;
			}
			result[i] += this[j] * other[(i + j + 1) % n] - this[(i + j + 1) % n] * other[j];
		}
	}
	return result;
}

template<valid_numeric T>
T Vector<T>::dotProduct(const Vector<T>& other)
{
	if (this->n != other.n) {
		throw std::invalid_argument("–азмеры векторов не совпадают!");
	}
	Vector<T> buffer = this * other;
	T result = 0;
	for (int i = 0; i < n; i++) {
		result += buffer[i];
	}
	return result;
}
