// Lesson21.cpp:   first degree equation
//
//  Solve equation:
//      ax + b = 0    => 
//          x = -b/a  
//
//  Define structures
//
#include <iostream>
#include <cmath>
using namespace std;


struct FirstDegreeParams {
    float a;
    float b;
};

int main()
{
    FirstDegreeParams params {10, 20};
 
    std::cout << "MathLesson23 ================================" 
              << std::endl;

    std::cout << "Solve equation " << params.a << "x + " << params.b << " = 0." 
                << std::endl;
    
    if (params.a != 0)
    {
        std::cout << "\tSolution: x = " << - (params.b / params.a) << std::endl;
    }
    else
    {
        std::cout << "\tNo solution, a parameter can't be 0." << std::endl;
    }

    std::cout << std::endl;
}
