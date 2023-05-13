#ifndef IS_LAB_1_VECTOR_H
#define IS_LAB_1_VECTOR_H

struct Vector2 {
  float x;
  float y;

  Vector2() : x(0), y(0) {}

  Vector2(float _x, float _y) : x(_x), y(_y) {}
};

Vector2 AddVectors(Vector2 v1, Vector2 v2);

#endif //IS_LAB_1_VECTOR_H
