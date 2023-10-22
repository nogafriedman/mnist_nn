// Matrix.h
#ifndef MATRIX_H
#define MATRIX_H
#define RANGE_ERROR_MSG "ERROR: Index is out of range."
#define LEN_ERROR_MSG "ERROR: Dimensions aren't equal, can't do arithmetic "\
"operation."
#define STREAM_ERROR_MSG "ERROR: Invalid stream file."
#include <iostream>

/**
 * @struct matrix_dims
 * @brief Matrix dimensions container. Used in MlpNetwork.h and main.cpp
 */
typedef struct matrix_dims
{
	int rows, cols;
} matrix_dims;

/**
 * class Matrix - a one-dimensional array that represents rows and cols of a
 * Matrix.
 * consists of two fields: matrix_dims struct (with rows and cols ints), and
 * data (the array that contains the vectors).
 */
class Matrix
{
 private:
  matrix_dims _dims{}; // matrix dimensions
  float *_data; // matrix array

 public:
  // constructors:

/**
 * Class constructor - Inits a Matrix of the dimensions of rows and cols given
 * to it as arguments, both have to be positive ints. Inits elements to 0.
 */
  Matrix(int rows, int cols);

/**
 * Default class constructor - Inits a 1x1 Matrix with all elements set to 0.
 */
  Matrix ();

  // copy constructor:
/**
 * Copy constructor - Inits a new Matrix object and copies the data from the
 * Matrix given as argument as it's new data.
 * @param m - const Matrix reference
 * @return a new Matrix which is a copy of the argument Matrix
 */
  Matrix(const Matrix& m);

  // destructor:
/**
 * Class destructor - Deletes the Matrix object and it's data.
 */
  ~Matrix();

  // getters:

/**
 * returns the rows field of the Matrix object and doesn't make any changes.
 * @return _rows (int - by value)
 */
  int get_rows() const;

/**
 * returns the cols field of the Matrix object and doesn't make any changes.
 * @return _cols (int - by value)
 */
  int get_cols() const;

  // functions & methods:

/**
 * transposes the matrix the function is called upon.
 * @return reference of the given matrix, transposed
 */
  Matrix& transpose();

/**
 * returns the Matrix as a vector (a list of all of it's elements as rows
 * and one column).
 * @return reference to the given Matrix, as a vector
 */
  Matrix& vectorize();

/**
 * prints the Matrix to stdout. Doesn't change any element.
 */
  void plain_print() const;

/**
 * Calculates the matrix that is the result of the multiplication of
 * same-indices elements in both matrices:
 * dot_res(i, j) = this(i, j) * other(i, j)
 * Does not make any changes to the arguments.
 * @param other const Matrix reference to multiply with
 * @return Matrix - by value
 */
  Matrix dot(const Matrix& other) const;

/**
 * calculates the Frobenius norm of the Matrix it's called upon, doesn't make
 * changes.
 * @return float of the norm calculated
 */
  float norm() const;

  // operators:

/**
 * Operator that calculates the sum of a matrix with another Matrix, and
 * doesn't make changes to the given Matrix.
 * @param other const Matrix reference
 * @return sum Matrix - by value
 */
  Matrix operator+(const Matrix& other) const;

/**
 * Operator assigns the argument Matrix to another created Matrix.
 * @param other const Matrix reference
 * @return Matrix reference of the assigned Matrix
 */
  Matrix& operator=(const Matrix& other);

/**
 * Operator that calculates the multiplication of a matrix with another
 * Matrix, and doesn't make changes to the given Matrix.
 * @param other const Matrix reference
 * @return multiplication result Matrix - by value
 */
  Matrix operator*(const Matrix& other) const;

/**
 * Operator that calculates the multiplication of a matrix with a scalar
 * from the right, and doesn't make changes to the given Matrix.
 * @param x float
 * @return multiplication result Matrix - by value
 */
  Matrix operator*(float x) const;

/**
 * Operator that calculates the multiplication of a matrix with a scalar
 * from the left.
 * @param x float
 * @param other const Matrix reference
 * @return multiplication result Matrix - by value
 */
  friend Matrix operator*(float x, const Matrix& other);

/**
 * Operator that adds the elements of the given matrix to the elements data
 * of another matrix (changes their values).
 * @param other const Matrix reference
 * @return Matrix reference of the changed Matrix
 */
  Matrix& operator+=(const Matrix& other);

/**
 * Operator that returns the data in the i'th index of the Matrix data
 * array, and does not make any changes.
 * @param i int
 * @return float of the data saved in the i'th index
 */
  float operator[](int i) const;

/**
 * Operator that allows to reach the i'th index of the Matrix and make
 * changes to it.
 * @param i int
 * @return float of the data saved in the i'th index
 */
  float& operator[](int i);

/**
 * Operator that returns the data in the (i, j) location of the Matrix data
 * array, and does not make any changes.
 * @param i int
 * @param j int
 * @return float reference of the data saved in the (i, j) location
 */
  float operator()(int i, int j) const;

/**
 * Operator that allows access to the (i, j) location in the Matrix data
 * array and can be used to make changes to it.
 * @param i int
 * @param j int
 * @return float reference of the data saved in the (i, j) location
 */
  float& operator()(int i, int j);

/**
 * Operator that allows communication with the user via std output.
 * @param os std::ostream reference
 * @param mat const Matrix reference
 * @return std::ostream reference
 */
  friend std::ostream& operator<<(std::ostream& os, const Matrix& mat);


/**
 * Operator that allows communication with the user via std input.
 * @param os std::istream reference
 * @param mat const Matrix reference
 * @return std::istream reference
 */
  friend std::istream& operator>>(std::istream& is, const Matrix& mat);
};

#endif //MATRIX_H