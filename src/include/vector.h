//
// Created by Sasha on 3/30/2023.
//

#ifndef MYGAME_VECTOR_H
#define MYGAME_VECTOR_H

#endif //MYGAME_VECTOR_H

//=======================================================
//Include guard
#ifndef VECTOR_H
#define VECTOR_H
//=======================================================

#include <vector>
#include <cmath>
#include <string>

#include "matrix.hpp"

class Vector3
{
public:
    float x;
    float y;
    float z;

    Vector3();
    Vector3(float x);
    Vector3(float x, float y);
    Vector3(float x, float y, float z);

    void rotate(Matrix rotationMatrix, Vector3 origin);

    std::string toString();

    float sqLength();
    float length();

    void operator+=(Vector3 v);
    void operator+=(float amount);
    void operator-=(Vector3 v);
    void operator-=(float amount);

    Vector3 operator+(Vector3 v);
    Vector3 operator-(Vector3 v);
    Vector3 operator*(float amount);
    Vector3 operator/(float amount);
};

#endif