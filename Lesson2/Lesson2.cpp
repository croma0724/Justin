/******************************************************
 * Lesson2.h:   first degree equation
 *
 *****************************************************/
#include <iostream>
#include "Lesson2.h"
using namespace std;

FDEq::FDEq(float a, float b) : params{ a,b }, root(0.0)
{
}

FDEq::FDEq(void) : params{ 0.0, 0.0 }, root(0.0)
{}

void FDEq::setFDEq(float a, float b)
{
  params = { a, b };
}

void FDEq::setFDEqTerm()
{
  std::cout << "Enter parameter 'a' for ax + b equation as a float:\n";
  cin >> params.a;

  std::cout << "\bEnter parameter 'b' for ax + b equation as a float:\n";
  cin >> params.b;
}

string FDEq::calculateFDEroot()
{
  string ret;
  root = 0.0;

  if (isValidFDEqParams(params) == true)
  {
    root = -(params.b / params.a);
    ret = displayFDEq() + "Root: " + to_string(root) + "\n\n";
  }
  else
  {
    ret = displayFDEq() + "Error: invalid equation parameter.\n\n";
  }

  return ret;
}

string FDEq::displayFDEq() const
{
  string ret = "Equation:  " + std::to_string(params.a) + " x X + " + 
        std::to_string(params.b) + " = 0.   ";
  return ret;
}

bool FDEq::isValidFDEqParams(FDEqParams& param) const
{
  return param.a != 0 && param.b != 0;
}
