// Lesson21.cpp:   first degree equation
//
//  Solve equation:
//      ax + b = 0    => 
//          x = -b/a  
//
#include <iostream>
#include <cmath>
using namespace std;


int main()
{
    int a = 10;
    int b = 20;

    std::cout << "MathLesson21 ================================" 
              << std::endl;

    std::cout << "Solve equation " << a << "x + " << b << " = 0." << std::endl;
    
    if (a != 0)
    {
        std::cout << "\tSolution: x = " << -b / a << std::endl;
    }
    else
    {
        std::cout << "\tNo solution, a parameter can't be 0." << std::endl;
    }

    std::cout << std::endl;
}
