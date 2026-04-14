/******************************************************
 * Lesson2Main.cpp:   solve first degree equation
 *
 *  Solve equation:     ax + b = 0    =>  x = -b/a
 *  
 * Case 1:  default FDEqParams 
 * Case 2:  retrieve FDEqParams from console
 *
 *****************************************************/
#include <iostream>
#include <string>
#include "Lesson2.h"
using namespace std;


int main()
{
  std::cout << "Solve first degree equation aX + b = 0.\n\n";
  
  // Preconfigured parameters 
  {
    FDEq eq1(-2, 6);
    std::cout << eq1.calculateFDEroot();

    eq1.setFDEqTerm();
    std::cout << eq1.calculateFDEroot();

    eq1.setFDEq(0, 2.4);
    std::cout << eq1.calculateFDEroot();

    eq1.setFDEq(3.1, 0.0);
    std::cout << eq1.calculateFDEroot();
  } 
  
  return 0;
}

