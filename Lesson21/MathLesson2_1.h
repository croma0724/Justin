///////////////////////////////////////////////
// Lesson2.h:   first degree equation
//
//  Solve equation:
//      ax + b = 0    => 
//          x = -b/a  
//  Exceptions:  
//      a = 0 => invalid, no equation   =>  b = 0 ???
///////////////////////////////////////////////      
#ifndef LESSON2_H
#define LESSON2_H

#include <iostream>
#include <string>
using namespace std;

// First degree equation paramters:  ax + b = 0
struct FirstDegreeParams {
    float a;
    float b;
};

class FirstDegree {
public:
    FirstDegree(FirstDegreeParams param);

    bool  getRoot(float &r);
    string display();
 
protected:
    void  calculateRoot();

private:
    struct FirstDegreeParams param;
    float root;
    bool  res; 
};

#endif  // 