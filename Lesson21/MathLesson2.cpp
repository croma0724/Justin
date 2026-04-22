// Lesson2.cpp:   first degree equation
//
//  Solve equation:
//      ax + b = 0    => 
//          x = -b/a  
//
#include "MathLesson2.h"
#include <cmath>
using namespace std;
 

int main()
{
    std::cout << "MathLesson2 ================================" 
              << std::endl;
    FirstDegreeParams params {10, 20};
    float root;
    FirstDegree eq1(params);
    
    std::cout << "Solve equation " << params.a << "x + " << params.b << " = 0." << std::endl;
    eq1.getRoot(root);

 
    std::cout << std::endl;
}


FirstDegree::FirstDegree(FirstDegreeParams par) : param(par), root(0.0), res(false) 
{}

bool FirstDegree::getRoot(float &r)
{
    calculateRoot();
    if (res == true)
    {
        r = root;
    }

    return res;
}

void FirstDegree::calculateRoot()
{
    if (param.a != 0)
    {
        root = - (param.b / param.a);
        res = true;
    }
}

//string display();
 