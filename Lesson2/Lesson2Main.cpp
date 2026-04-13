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
  float root = 0.0;
  bool ret = false;
  string consout;

  // Case 1
  FDEqParams params{ 10, 20 };
  if (validateFDEqParams(params) == true)
  {
    ret = calculateRootFirstDegreeEq(&root, params);                                                                                                            
    consout = displayEquationByParam(params) + "[" + std::to_string(root) + "]\n";    
  }
  else
  {
    consout = displayEquationByParam(params);
  }
  std::cout << consout << "\n";

  params = { 0.0, 0.0 };
  
  // Case 2
  while (true)
  {
    populateFDEqParams(&params);
    if (validateFDEqParams(params) == true)
      break;
  }
  if (validateFDEqParams(params) == true)
  {
    ret = calculateRootFirstDegreeEq(&root, params);
    consout = displayEquationByParam(params) + "[" + std::to_string(root) + "]\n";
  }
  else
  {
    consout = displayEquationByParam(params);
  }
  std::cout << consout << "\n";


  std::cout << std::endl;
}

