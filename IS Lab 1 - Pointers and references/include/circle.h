#ifndef IS_LAB_1_CIRCLE_H
#define IS_LAB_1_CIRCLE_H

#include "vector_2.h"

struct Circle {
  float radius;
  Vector2 position;

  Circle() : radius(), position() {}

  explicit Circle(float _radius) : radius(_radius), position() {}

  Circle(float _radius, Vector2 _position) : radius(_radius), position(_position) {}
};

void MoveCircle(Circle &circle, Vector2 v);

void MoveCirclePtr(Circle *circle, Vector2 v);

#endif //IS_LAB_1_CIRCLE_H
