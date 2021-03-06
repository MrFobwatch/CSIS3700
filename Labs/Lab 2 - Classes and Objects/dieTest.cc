#include <iostream>
#include "die.h"

int main() {
  srand(time(NULL));
  Die d1, d2;
  Die d20(20);
  Die coin(2), octa(8);
  
  std::cout << "d1:" << d1.roll() << std::endl;
  std::cout << "d2:" << d2.roll() << std::endl;
  std::cout << "d20:" << d20.roll() << std::endl;
  return 0;
}
