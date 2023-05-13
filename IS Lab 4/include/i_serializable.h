#ifndef IS_LAB_4_INCLUDE_I_SERIALIZABLE_H_
#define IS_LAB_4_INCLUDE_I_SERIALIZABLE_H_

#include <string>

class ISerializable {
 public:
  [[nodiscard]] virtual std::string Serialize() const = 0;
};

#endif //IS_LAB_4_INCLUDE_I_SERIALIZABLE_H_
