#ifndef IS_LAB_4_INCLUDE_SHAPE_SYSTEM_H_
#define IS_LAB_4_INCLUDE_SHAPE_SYSTEM_H_

#include "abstract_serializable_shape_body.h"
#include "vector2.h"

#include <vector>

class ShapeSystem {
 public:
  ~ShapeSystem();

  [[nodiscard]] double GetTotalSquare() const;

  [[nodiscard]] double GetTotalPerimeter() const;

  [[nodiscard]] Vector2 GetCenterOfGravity() const;

  [[nodiscard]] size_t GetTotalMemory() const;

  void Add(AbstractSerializableShapeBody *body);

  void SortByMass();

  void Print() const;

 private:
  std::vector<AbstractSerializableShapeBody*> _shapes;
};

#endif //IS_LAB_4_INCLUDE_SHAPE_SYSTEM_H_
