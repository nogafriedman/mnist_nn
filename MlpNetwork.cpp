#include "MlpNetwork.h"

MlpNetwork::MlpNetwork(const Matrix* weights, const Matrix* biases) :
_r1(Dense(weights[0], biases[0], activation::relu)),
_r2(Dense(weights[1], biases[1], activation::relu)),
_r3(Dense(weights[2], biases[2], activation::relu)),
_r4(Dense(weights[3], biases[3], activation::softmax)) {};

digit MlpNetwork::operator() (const Matrix &mat) const
{
  Matrix r1_output = _r1(mat);
  Matrix r2_output = _r2(r1_output);
  Matrix r3_output = _r3(r2_output);
  Matrix final_output = _r4(r3_output);

  unsigned int max_index = 0;
  float max_prob = 0;
  for (int i = 0; i < final_output.get_rows(); i++)
  {
    if (final_output[i] > max_prob)
    {
      max_index = i;
      max_prob = final_output[i];
    }
  }
  digit output_digit = {max_index, max_prob};
  return output_digit;
}