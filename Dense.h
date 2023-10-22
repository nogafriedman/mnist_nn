#ifndef DENSE_H
#define DENSE_H

#include "Activation.h"

/**
 * class Dense - represents a layer of the mlp network.
 * consists of three fields: weights (Matrix), bias (Matrix),
 * activation_func (an activation func of either type relu or softmax).
 */
class Dense
{
 private:
  Matrix _weights;
  Matrix _bias;
  ActivationFunc _activation_func;

 public:
  // constructor:

/**
 * Class constructor. Inits a Dense class objects. Contains 3 fields:
 * weights (Matrix), bias (Matrix), activation_func (Activation function).
 * @param weights - const Matrix reference
 * @param bias - const Matrix reference
 * @param activation_func - activation function
 */
  Dense(const Matrix& weights, const Matrix& bias, ActivationFunc
  activation_func) : _weights(weights), _bias(bias), _activation_func
  (activation_func) {};

  // getters:

/**
 * returns the weights field of the Dense object and doesn't make any changes.
 * @return _weights (Matrix - by value)
 */
  Matrix get_weights() const;

/**
 * returns the bias field of the Dense object and doesn't make any changes.
 * @return _bias (Matrix - by value)
 */
  Matrix get_bias() const;

/**
 * returns the activation function of the layer and doesn't make any changes.
 * @return activation function
 */
  ActivationFunc get_activation() const;

  // operators:

/**
 * applies the layer on the input vector and returns the output vector
 * (vector of class Matrix) based on calculations using the activation
 * function. Does not make changes to the input.
 * @param const Matrix reference
 * @return output Matrix - by value
 */
  Matrix operator()(const Matrix& mat) const;
};

#endif //DENSE_H
