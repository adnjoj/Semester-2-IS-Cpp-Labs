#ifndef IS_LAB_4_INCLUDE_ABSTRACT_SERIALIZABLE_SHAPE_BODY_H_
#define IS_LAB_4_INCLUDE_ABSTRACT_SERIALIZABLE_SHAPE_BODY_H_

#include "i_shape.h"
#include "i_serializable.h"
#include "abstract_physical_body.h"
#include "abstract_cpp_object.h"

class AbstractSerializableShapeBody
    : public IShape, public ISerializable, public AbstractPhysicalBody, public ICppObject {
 public:
  AbstractSerializableShapeBody(double x, double y, double mass) : AbstractPhysicalBody(x, y, mass) {}

  virtual ~AbstractSerializableShapeBody() = default;
};

#endif //IS_LAB_4_INCLUDE_ABSTRACT_SERIALIZABLE_SHAPE_BODY_H_
