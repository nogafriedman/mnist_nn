#include "Dense.h"

// constructor:
// in h file

// getters:
Matrix Dense::get_weights() const
{
  return _weights;
}

Matrix Dense::get_bias() const
{
 return _bias;
}

ActivationFunc Dense::get_activation() const
{
  return _activation_func;
}

// operator:
Matrix Dense::operator()(const Matrix& mat) const
{
  return _activation_func((*this)._weights * mat + (*this)._bias);
}
