#ifndef MYTEMPLATES_H
#define MYTEMPLATES_H

#include <cmath> // For abs

using namespace std;

// Template function: scalar_difference
template <typename T>
double scalar_difference(const T& param1, const T& param2) {
    return abs(param1.getScalarValue() - param2.getScalarValue());
}

// Template function: equals
template <typename T>
bool equals(const T& param1, const T& param2) {
    return param1 == param2; // Uses the overloaded == operator
}

#endif