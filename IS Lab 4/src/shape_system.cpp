#include "../include/shape_system.h"

#include <iostream>

ShapeSystem::~ShapeSystem() {
  for (auto & _shape : _shapes) {
    delete _shape;
  }
}

double ShapeSystem::GetTotalSquare() const {
  double result = 0;

  for (const AbstractSerializableShapeBody *shape : _shapes) {
    result += shape->Square();
  }

  return result;
}

double ShapeSystem::GetTotalPerimeter() const {
  double result = 0;

  for (const AbstractSerializableShapeBody *shape : _shapes) {
    result += shape->Perimeter();
  }

  return result;
}

Vector2 ShapeSystem::GetCenterOfGravity() const {
  if (_shapes.empty()) return {0, 0};

  Vector2 result{_shapes[0]->position};
  double sum_of_masses = _shapes[0]->mass;

  for (int i = 1; i < _shapes.size(); i++) {
    // m2 / (m1 + m2)
    // A + (B - A) * x
    // A * (1 - x) + B * x
    double k = _shapes[i]->mass / (_shapes[i]->mass + sum_of_masses);
    result = result * (1 - k) + _shapes[i]->position * k;
    sum_of_masses += _shapes[i]->mass;
  }

  return result;
}

size_t ShapeSystem::GetTotalMemory() const {
  size_t result = 0;

  for (const AbstractSerializableShapeBody *shape : _shapes) {
    result += shape->Size();
  }

  return result;
}

void ShapeSystem::Add(AbstractSerializableShapeBody *body) {
  _shapes.push_back(body);
}

void ShapeSystem::SortByMass() {
  std::sort(_shapes.begin(), _shapes.end());
}

void ShapeSystem::Print() const {
  for (const AbstractSerializableShapeBody *shape : _shapes) {
    std::cout << shape->Serialize() << std::endl;
  }
}
