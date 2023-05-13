#include "include/menu.h"

#include <iostream>

int main() {
  Menu menu(std::cout, std::cout);

  std::cout << ">>> ";
  std::string command;

  while (std::getline(std::cin, command)) {
    if (command == "exit") break;

    menu.HandleCommand(command);
    std::cout << ">>> ";
  }

  return 0;
}
