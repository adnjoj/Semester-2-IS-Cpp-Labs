#ifndef IS_LAB_4_INCLUDE_ABSTRACT_PHYSICAL_BODY_H_
#define IS_LAB_4_INCLUDE_ABSTRACT_PHYSICAL_BODY_H_

#include "vector2.h"

class AbstractPhysicalBody {
 public:
  Vector2 position;
  double mass;

  AbstractPhysicalBody(double x, double y, double mass) : position(x, y), mass(mass) {}

  bool operator==(AbstractPhysicalBody object) const;

  bool operator!=(AbstractPhysicalBody object) const;

  bool operator<(AbstractPhysicalBody object) const;

  bool operator<=(AbstractPhysicalBody object) const;

  bool operator>(AbstractPhysicalBody object) const;

  bool operator>=(AbstractPhysicalBody object) const;
};

#endif //IS_LAB_4_INCLUDE_ABSTRACT_PHYSICAL_BODY_H_
