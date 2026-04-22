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
typedef struct FDEqParams {
    float a;
    float b;
} FDEqParams;

// populateFDEqParams:  populate FDEqParams structure from console
// @output: p, structure address
// @return: true: completed ok
//          false: failed, a = 0 or didn't complete 
//
bool populateFDEqParams(FDEqParams* p);

// validateFDEqParams:  validate a != 0
// @input: p, structure 
// @return: true: valid
//          false: invalid
//
bool validateFDEqParams(FDEqParams p);

// calculateRootFirstDegreeEq: calculate first degree equation
// @input:  param, equation parameters
// @output: proot or 0 when root invalid
// @return: true, <proot> contains the root
//          false: invalid structure
//
bool calculateRootFirstDegreeEq(float* proot, FDEqParams param);

#endif  // 