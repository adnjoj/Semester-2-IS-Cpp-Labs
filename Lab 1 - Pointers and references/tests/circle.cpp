#include "../include/vector_2.h"
#include "../include/circle.h"

#include <iostream>

void TestMoveCircle(int tests_count, std::pair<Circle, Vector2> test_cases[], Circle expected[]) {
  std::cout << std::endl << "Testing MoveCircle procedure:" << std::endl << std::endl;

  for (int i = 0; i < tests_count; i++) {
    Circle c = test_cases[i].first;
    Vector2 v = test_cases[i].second;

    MoveCircle(c, v);

    assert(
        c.radius == expected[i].radius &&
            c.position.x == expected[i].position.x &&
            c.position.y == expected[i].position.y
    );

    std::cout << "    Test " << i + 1 << " passed" << std::endl;
  }

  std::cout << std::endl << "MoveCircle procedure passed all tests!" << std::endl;
}

void TestMoveCirclePtr(int tests_count, std::pair<Circle, Vector2> test_cases[], Circle expected[]) {
  std::cout << std::endl << "Testing MoveCirclePtr procedure:" << std::endl << std::endl;

  for (int i = 0; i < tests_count; i++) {
    Circle c = test_cases[i].first;
    Vector2 v = test_cases[i].second;

    MoveCirclePtr(&c, v);

    assert(
        c.radius == expected[i].radius &&
            c.position.x == expected[i].position.x &&
            c.position.y == expected[i].position.y
    );

    std::cout << "    Test " << i + 1 << " passed" << std::endl;
  }

  std::cout << std::endl << "MoveCirclePtr procedure passed all tests!" << std::endl;
}

void TestCircleMotion() {
  std::pair<Circle, Vector2> test_cases[] = {
      std::make_pair(Circle(), Vector2()),
      std::make_pair(Circle(5), Vector2(3, 4)),
      std::make_pair(Circle(3.5, Vector2(0.1, 0.1)), Vector2(0.2, 0.2)),
      std::make_pair(Circle(1.5, Vector2(100.01, 200.02)), Vector2(0.02, 0.01))
  };

  Circle expected[] = {
      Circle(0),
      Circle(5, Vector2(3, 4)),
      Circle(3.5, Vector2(0.3, 0.3)),
      Circle(1.5, Vector2(100.03, 200.03))
  };

  TestMoveCircle(4, test_cases, expected);
  TestMoveCirclePtr(4, test_cases, expected);
}
