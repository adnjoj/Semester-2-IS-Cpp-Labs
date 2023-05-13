#ifndef IS_LAB_4_INCLUDE_I_SHAPE_H_
#define IS_LAB_4_INCLUDE_I_SHAPE_H_

class IShape {
 public:
  [[nodiscard]] virtual double Square() const = 0;

  [[nodiscard]] virtual double Perimeter() const = 0;
};

#endif //IS_LAB_4_INCLUDE_I_SHAPE_H_
