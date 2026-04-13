/******************************************************
 * Lesson2.h:   first degree equation
 *
 *****************************************************/
#include <iostream>
#include "Lesson2.h"
using namespace std;
 
bool calculateRootFirstDegreeEq(float* proot, FDEqParams param)
{
  bool ret = false;

  if (proot == NULL)
  {
    std::cout << "Failed to extract root, invalid paameters input!\n";
    return ret;
  }

  *proot = 0;
  if (validateFDEqParams(param) == false)
  {
    return ret;
  }

  *proot = -(param.b / param.a);
  ret = true;

  return ret; 
}

void populateFDEqParams(FDEqParams* pparam)
{
  std::cout << "Enter parameter 'a' for ax + b equation as a float:\n";
  cin >> pparam->a;

  std::cout << "\bEnter parameter 'b' for ax + b equation as a float:\n";
  cin >> pparam->b;
}

bool validateFDEqParams(FDEqParams param)
{

  bool ret = false;

  if (param.a == 0)
  {
    std::cout << "Invalid equation paramete,  'a' = 0, resulting equation b = 0\n";
    return ret;
  }

  if (param.b == 0)
  {
    std::cout << "Invalid equation paramete,  'b' = 0, resulting equaion aX = 0\n";
    return ret;
  }

  ret = true;
  return ret;
}

string displayEquationByParam(FDEqParams param)
{
  string out;
  bool ret = validateFDEqParams(param);
  if (ret == true)
  {
    out = "Equation " + std::to_string(param.a) + " x X + " + std::to_string(param.b) + 
            " = 0 root:  ";
  }
  else
  {
    out = "Equation  " + std::to_string(param.a) + " x X + " + std::to_string(param.b) + 
            " = 0, parameters {" + std::to_string(param.a) + "," + 
            std::to_string(param.b) + " invalid!";
  } 

  return out;
}