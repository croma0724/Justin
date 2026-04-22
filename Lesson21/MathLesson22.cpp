// Lesson21.cpp:   first degree equation
//
//  Equation:
//      ax + b = 0    => 
//          x = -b/a  
//  Solve 3 equations, 1 invalid.
// 
#include <iostream>
#include <cmath>
using namespace std;


int main()
{
    float a = 10;
    float b = 20;
   
    std::cout << "MathLesson22 ================================" << std::endl;

    // First equation 10 x + 20 = 0
    std::cout << "Solve equation " << a << "x + " << b << " = 0." << std::endl;
    if (a != 0)
    {
        float ret = -b / a;
        std::cout << "\tSolution: x = " << ret << std::endl;
    }
    else
    {
        std::cout << "\tNo solution, a parameter can't be 0." << std::endl;
    }

    // Second equation 10 x + 5 = 0
    a = 10;
    b = 5;
    std::cout << std::endl << "Solve equation " << a << "x + " << b << " = 0." 
               << std::endl;
    if (a != 0)
    {
        float ret = -b / a;        
        std::cout << "\tSolution: x = " << ret << std::endl;
    }
    else
    {
        std::cout << "\tNo solution, a parameter can't be 0." << std::endl;
    }

    // Third equation 0 x + 5 = 0
    a = 0;
    b = 5;
    std::cout << std::endl << "Solve equation " << a << "x + " << b << " = 0." 
               << std::endl;
//    if (a != 0)
    {
        std::cout << "\tSolution: x = " << -b / a << std::endl;
    }
//    else
//    {
//       std::cout << "\tNo solution, a parameter can't be 0." << std::endl;/
//    }

    std::cout << std::endl;
}
