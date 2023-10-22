#include "Matrix.h"
#include <stdexcept>
#include <iostream>
#include <cmath>
#define PROB_VALUE 0.1
#define SPACE " "
#define ASTERISK "**"
#define DOUBLESPACE "  "
#define COL_VECTOR 1

// constructor:
Matrix::Matrix(int rows, int cols)
{
  if (rows <= 0 || cols <= 0) // check rows & cols length validity
  {
    throw std::length_error (LEN_ERROR_MSG);
  }
 _dims.rows = rows;
 _dims.cols = cols;
 _data = new float[rows * cols] {0};
}

// default constructor:
Matrix::Matrix() : Matrix(1,1) {}

// copy constructor:
Matrix::Matrix(const Matrix& other) :
Matrix(other.get_rows(), other.get_cols()) // constructor call
{
  for (int i = 0; i < other.get_rows(); i++) // copy data from matrix to matrix
  {
    for (int j = 0; j < other.get_cols(); j++)
    {
      (*this)(i, j) = other(i, j);
    }
  }
}

// destructor:
Matrix::~Matrix ()
{
  delete[] _data;
  _data = nullptr;
}

// functions & methods:
int Matrix::get_rows () const
{
  return _dims.rows;
}

int Matrix::get_cols () const
{
  return _dims.cols;
}

Matrix& Matrix::transpose()
{
  int pre_rows = (*this).get_rows();
  int pre_cols = (*this).get_cols();
  auto *new_mat = new float[pre_rows * pre_cols];
  for (int i = 0; i < pre_rows; i++)
  {
    for (int j = 0; j < pre_cols; j++)
    {
      new_mat[j * pre_rows + i] = _data[i * pre_cols + j];
    }
  }
  delete[] this->_data;
  this->_data = new_mat;
  this->_dims = {pre_cols, pre_rows};
  return *this;
}

Matrix& Matrix::vectorize()
{
  (*this)._dims.rows = (*this).get_rows() * (*this).get_cols();
  (*this)._dims.cols = COL_VECTOR;
  return *this;
}

void Matrix::plain_print() const
{
  for (int i = 0; i < (*this).get_rows(); i++)
  {
    for (int j = 0; j < (*this).get_cols(); j++)
    {
      std::cout << (*this)(i, j) << SPACE;
    }
    std::cout << std::endl;
  }
}

Matrix Matrix::dot(const Matrix& other) const
{
  if (((*this).get_rows () != other.get_rows ()) || ((*this).get_cols () !=
                                                     other.get_cols ()))
  {
    throw std::length_error (LEN_ERROR_MSG);
  }
  Matrix dot_res = Matrix(other.get_rows(), other.get_cols());
  for (int i = 0; i < other.get_rows() * other.get_cols(); i++)
  {
    dot_res[i] = (*this)[i] * other[i];
  }
  return dot_res;
}

float Matrix::norm() const
{
  float sum = 0;
  for (int i = 0; i < (*this).get_rows() * (*this).get_cols(); i++)
  {
    sum += powf(((*this)[i]), 2);
  }
  return sqrtf (sum);
}

// operators:
Matrix Matrix::operator+(const Matrix& other) const
{ // check that dimensions are equal, otherwise can't do arithmetic operation
  if (this->_dims.rows != other.get_rows() ||
  this->_dims.cols != other.get_cols())
  {
    throw std::length_error(LEN_ERROR_MSG);
  }
  Matrix sum_matrix = Matrix(this->get_rows(),this->get_cols());
  for (int i = 0; i < this->get_rows(); i++) // copy data from matrix to matrix
  {
    for (int j = 0; j < this->get_cols(); j++)
    {
      sum_matrix(i, j) = (*this)(i, j) + other(i, j);
    }
  }
  return sum_matrix;
}

Matrix& Matrix::operator=(const Matrix& other)
{ // check that objects are not the same
  if (this != &other)
  { // check that dimensions are equal
    if (this->_dims.rows != other.get_rows() ||
    this->_dims.cols != other.get_cols())
    {
      (*this)._dims.rows = other.get_rows();
      (*this)._dims.cols = other.get_cols();
    }
    delete[] (*this)._data;
    auto *new_mat = new float[other.get_rows() * other.get_cols()] {0};
    for (int i = 0; i < other.get_rows() * other.get_cols(); i++)
    {
      new_mat[i] = other[i];
    }
    (*this)._data = new_mat;
  }
  return *this;
}

Matrix Matrix::operator*(const Matrix& other) const // matrix multiplication
{ // check dimensions:
  if (this->get_cols() != other.get_rows())
  {
    throw std::length_error(LEN_ERROR_MSG);
  }
  Matrix mult_mat = Matrix(this->_dims.rows, other.get_cols());
  for (int i = 0; i < this->get_rows(); i++)
  {
    for (int j = 0; j < other.get_cols(); j++)
    {
      for (int k = 0; k < other.get_rows (); k++)
      {
        mult_mat (i, j) += ((*this) (i, k) * other (k, j));
      }
    }
  }
  return mult_mat;
}

Matrix Matrix::operator*(float x) const // scalar from right
{
  Matrix mult_mat = Matrix(this->get_rows(), this->get_cols());
  for (int i = 0; i < this->get_rows() * get_cols(); i++)
  {
    mult_mat[i] = (*this)[i] * x;
  }
  return mult_mat;
}

Matrix operator*(float x, const Matrix& other) // scalar from left
{
  return other * x;
}

Matrix& Matrix::operator+=(const Matrix& other)
{
  *this = *this + other;
  return *this;
}

float Matrix::operator[](int i) const // read only
{
  if (i < 0 || _dims.rows * _dims.cols <= i)
  {
    throw std::out_of_range(RANGE_ERROR_MSG);
  }
  return _data[i];
}

float& Matrix::operator[](int i) // non const
{
  if (i < 0 || _dims.rows * _dims.cols <= i)
  {
    throw std::out_of_range(RANGE_ERROR_MSG);
  }
  return _data[i];
}

float Matrix::operator()(int i, int j) const // read only
{
  if (i < 0 || j < 0 || this->get_rows() <= i || this->get_cols() <= j)
  {
    throw std::out_of_range(RANGE_ERROR_MSG);
  }
  return _data[i * _dims.cols + j];
}

float& Matrix::operator()(int i, int j) // non const
{
  if (i < 0 || j < 0 || this->get_rows() <= i || this->get_cols() <= j)
  {
    throw std::out_of_range(RANGE_ERROR_MSG);
  }
  return _data[i * _dims.cols + j];
}

std::ostream& operator<<(std::ostream& os, const Matrix& mat)
{
  for (int i = 0; i < mat.get_rows(); i++)
  {
    for (int j = 0; j < mat.get_cols(); j++)
    {
      if (mat(i, j) > PROB_VALUE)
      {
        os << ASTERISK;
      }
      else
      {
        os << DOUBLESPACE;
      }
    }
    os << std::endl;
  }
  return os;
}

std::istream& operator>>(std::istream& is, const Matrix& mat)
{
  is.seekg(0, std::ios::end);
  long long length = is.tellg();
  long to_read = (long)(sizeof(float)) * mat.get_rows() * mat.get_cols();
  if ((length < to_read))
  {
    throw std::runtime_error(STREAM_ERROR_MSG);
  }
  is.seekg(0, std::ios::beg);
  is.read((char *)mat._data, length);
  if (!is.good())
  {
    throw std::runtime_error(STREAM_ERROR_MSG);
  }
  return is;
}