//MlpNetwork.h

#ifndef MLPNETWORK_H
#define MLPNETWORK_H

#include "Dense.h"

#define MLP_SIZE 4

/**
 * @struct digit
 * @brief Identified (by Mlp network) digit with
 *        the associated probability.
 * @var value - Identified digit value
 * @var probability - identification probability
 */
typedef struct digit {
	unsigned int value;
	float probability;
} digit;

const matrix_dims img_dims = {28, 28};
const matrix_dims weights_dims[] = {{128, 784},
									{64,  128},
									{20,  64},
									{10,  20}};
const matrix_dims bias_dims[] = {{128, 1},
								 {64,  1},
								 {20,  1},
								 {10,  1}};

/**
 * Class MlpNetworlk. Represents the four layers that can be applied on a
 * given vector in order to read it's data and process the image it's made of.
 * Contains four fields that represent the four layers: _r1, _r2, _r3, _r4.
 */
class MlpNetwork
{
 private:
  Dense _r1, _r2, _r3, _r4;

 public:
/**
 * Class constructor - Init's a new MlpNetwork object with four layers based
 * on the given parameters.
 * @param weights const Matrix pointer
 * @param biases const Matrix pointer
 * @return a new MlpNetwork object
 */
  MlpNetwork(const Matrix* weights, const Matrix* biases);

/**
 * Operator that applies the layers on a given vector in order to read it's
 * data and determine the digit it represents. Doesn't make changes.
 * @param mat const Matrix reference
 * @return digit struct that contains an int value of the digit read, and
 * float of the probability of success in reading that digit.
 */
  digit operator()(const Matrix& mat) const;
};

#endif // MLPNETWORK_H