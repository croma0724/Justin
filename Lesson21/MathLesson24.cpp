// Lesson21.cpp:   first degree equation
//
//  Solve equation:
//      ax + b = 0    => 
//          x = -b/a  
//
//  Define function
//
#include <iostream>
#include <cmath>
using namespace std;

struct FirstDegreeParams {
    float a;
    float b;
};


// Solve first degree equation.   
// Input:  par, parameters
// Output: res, result
// Return: true: valid equation, res contains equation root 
//         false: invalid equation, res set to 0/
// 
bool FirstDegreeRoot(float &res, struct FirstDegreeParams par);

int main()
{
    FirstDegreeParams params {10, 20};
    float root = 0.0;
    bool result = false;

    std::cout << "MathLesson24 ================================" 
              << std::endl;

    result = FirstDegreeRoot(root, params);
    if (result == true)
    {
        std::cout << "Solve equation " << params.a << "x + " << params.b << " = 0." 
                << "\tSolution: x = " << root << std::endl;
    }
    else
    {
        std::cout << "\tNo solution, a parameter can't be 0." << std::endl;
    }

    std::cout << std::endl;
}


bool FirstDegreeRoot(float &res, struct FirstDegreeParams param)
{
    bool ret = false;
   
    if (param.a != 0)
    {
        res = - (param.b / param.a);
        ret = true;
    }
       
    return ret;
}