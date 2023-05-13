#include "include/shape_system.h"
#include "include/rectangle/basic_dialog_initializer.h"
#include "include/isosceles_trapezoid/basic_dialog_initializer.h"
#include "include/rectangle/basic_serializer.h"
#include "include/isosceles_trapezoid/basic_serializer.h"

#include <iostream>

int main() {
  ShapeSystem shape_system;

  RectangleBasicDialogInitializer rect_initializer(std::cin);
  IsoscelesTrapezoidBasicDialogInitializer trapezoid_initializer(std::cin);

  RectangleBasicSerializer rect_serializer;
  IsoscelesTrapezoidBasicSerializer trapezoid_serializer;

  std::string command;

  while (std::cin >> command) {
    if (command == "print") {
      shape_system.Print();
    } else if (command == "sort") {
      shape_system.SortByMass();
    } else if (command == "square") {
      std::cout << shape_system.GetTotalSquare() << std::endl;
    } else if (command == "perimeter") {
      std::cout << shape_system.GetTotalPerimeter() << std::endl;
    } else if (command == "memory") {
      std::cout << shape_system.GetTotalMemory() << std::endl;
    } else if (command == "gravity_center") {
      std::cout << shape_system.GetCenterOfGravity() << std::endl;
    } else if (command == "create_rect") {
      Rectangle *rect = rect_initializer.Initialize();
      rect->UseSerializer(&rect_serializer);
      shape_system.Add(rect);
    } else if (command == "create_trapezoid") {
      IsoscelesTrapezoid *trapezoid = trapezoid_initializer.Initialize();
      trapezoid->UseSerializer(&trapezoid_serializer);
      shape_system.Add(trapezoid);
    } else std::cout << "Unsupported command" << std::endl;
  }

  return 0;
}
