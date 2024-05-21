#pragma once
#include <concepts>
#include <type_traits>
template<typename T>
concept valid_second_max =
std::is_same<int, T>::value ||
std::is_same<float, T>::value ||
std::is_same<double, T>::value ||
std::is_same<char, T>::value;

template<typename T>
concept valid_numeric =
std::is_same<int, T>::value ||
std::is_same<float, T>::value ||
std::is_same<double, T>::value;