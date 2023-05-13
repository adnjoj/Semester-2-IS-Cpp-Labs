#include "../include/circle.h"

void MoveCircle(Circle &circle, Vector2 v) {
  circle.position = AddVectors(circle.position, v);
}

void MoveCirclePtr(Circle *circle, Vector2 v) {
  circle->position = AddVectors(circle->position, v);
}
