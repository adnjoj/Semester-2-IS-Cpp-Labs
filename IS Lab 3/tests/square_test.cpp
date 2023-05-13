#include "../include/square.h"

#include <iostream>
#include <vector>

void TestAreaComparison(const std::vector<Square> &squares, const std::vector<const char *> &operators, int op) {
  std::cout << "    Testing area " << operators[op] << ": " << std::endl;

  for (int i = 0; i < squares.size() - 1; i++) {
    Square a = squares[i];
    Square b = squares[i + 1];

    bool compared;
    bool expected;

    switch (op) {
      case 0:compared = a == b;
        expected = a.Side() == b.Side();
        break;

      case 1:compared = a != b;
        expected = a.Side() != b.Side();
        break;

      case 2:compared = a < b;
        expected = a.Side() < b.Side();
        break;

      case 3:compared = a <= b;
        expected = a.Side() <= b.Side();
        break;

      case 4:compared = a > b;
        expected = a.Side() > b.Side();
        break;

      case 5:compared = a >= b;
        expected = a.Side() >= b.Side();
        break;

      default:compared = true;
        expected = false;
        break;
    }

    assert(compared == expected);

    std::printf(
        "        Passed test %1$i: Square(%2$f * %2$f) %3$s%4$s Square(%5$f * %5$f)\n",
        i + 1,
        a.Side(),
        expected ? "" : "not ",
        operators[op],
        b.Side()
    );
  }

  std::cout << "    Passed all tests!" << std::endl << std::endl;
}

void TestMultiplyByNumber(const std::vector<Square> &squares) {
  std::cout << "    Testing multiplication by number" << std::endl;

  for (int i = 0; i < squares.size(); i++) {
    Square result = squares[i] * i;

    assert(result.Side() == squares[i].Side() * i);

    std::printf(
        "        Passed test %1$i: Square(%2$f * %2$f) * %3$f = Square(%4$f * %4$f)\n",
        i + 1,
        squares[i].Side(),
        (double) i,
        result.Side()
    );
  }

  std::cout << "    Passed all tests!" << std::endl << std::endl;
}

void TestMotion(const std::vector<Square> &squares) {
  std::cout << "    Testing motion by vector" << std::endl;

  for (int i = 0; i < squares.size(); i++) {
    Vector2 direction = Vector2(-i, i * 2);
    Square result = squares[i] + direction;

    assert(result.Position() == squares[i].Position() + direction);

    std::printf(
        "        Passed test %i: Square at (%f, %f) + (%f, %f) = Square at (%f, %f)\n",
        i + 1,
        squares[i].Position().x,
        squares[i].Position().y,
        direction.x,
        direction.y,
        result.Position().x,
        result.Position().y
    );
  }

  std::cout << "    Passed all tests!" << std::endl << std::endl;
}

void TestSquare() {
  std::cout << "Testing Square class: " << std::endl << std::endl;

  std::vector<Square> squares{
      Square(),
      Square(1, 2),
      Square(Vector2(2, 4)),
      Square(-5, 6, 10),
      Square(Vector2(12, 52), 9),
      Square(99, -1, 3, 15),
      Square(Vector2(-8, -9), 10, -5)
  };

  std::vector<const char *> operators{"==", "!=", "<", "<=", ">", ">="};

  for (int i = 0; i < operators.size(); i++) {
    TestAreaComparison(squares, operators, i);
  }

  TestMultiplyByNumber(squares);

  TestMotion(squares);
}
