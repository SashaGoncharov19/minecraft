//
// Created by Sasha on 3/30/2023.
//

#ifndef MYGAME_MATRIX_H
#define MYGAME_MATRIX_H

#endif //MYGAME_MATRIX_H

//=======================================================
//Include guard
#ifndef MATRIX_H
#define MATRIX_H
//=======================================================

#include <iostream>
#include <string>
#include <vector>

class Vector3; //Forward declaration

typedef std::vector<std::vector<float>> Matrix;

Matrix             matrixMultiplication(Matrix matrix1, Matrix matrix2);
std::vector<float> matrixVectorMultiplication(Matrix matrix, Vector3 *v);

char const *matrixToString(Matrix m);

#endif