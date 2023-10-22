#include "Matrix.h"
#include "Activation.h"
#include <cmath>

Matrix activation::relu(const Matrix& x)
{
  Matrix y = Matrix(x);
  for (int i = 0; i < x.get_rows() * x.get_cols(); i++)
  {
    if (x[i] < 0)
    {
      y[i] = 0;
    }
  }
  return y;
}

Matrix activation::softmax(const Matrix& x)
{
  Matrix y = Matrix(x);
  float sum = 0;
  for (int i = 0; i < x.get_rows(); i++)
  {
    float exp_res = std::exp(y[i]);
    y[i] = exp_res;
    sum += exp_res;
  }
  return (1 / sum) * y;
}