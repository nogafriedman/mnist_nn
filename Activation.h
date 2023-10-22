#include "Matrix.h"

#ifndef ACTIVATION_H
#define ACTIVATION_H

typedef Matrix (*ActivationFunc)(const Matrix&);

/**
 * namespace for activation functions of two types:
 * relu, softmax - both receive a const reference of a vector (of class
 * Matrix).
 */
namespace activation
{
    Matrix relu(const Matrix& x);
    Matrix softmax(const Matrix& x);
}

#endif //ACTIVATION_H