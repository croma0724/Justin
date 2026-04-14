/******************************************************
 * Lesson2.h:   first degree equation (FDEq)
 *
 *  Solve equation:
 *      ax + b = 0    => 
 *          x = -b/a  
 *  Exceptions:  
 *      a = 0 => invalid, no equation   =>  b = 0 ???
 *      b = 0 => undetermined, ax = 0 => x is always 0
 *****************************************************/
#ifndef LESSON2_H
#define LESSON2_H

#include <string> 
using namespace std;

// First degree equation paramters:  ax + b = 0
typedef struct FDEqParams {
    float a;
    float b;
} FDEqParams;


class FDEq {
public:
  // Constructor, populate object from arguments
  // @input:  a, b, FDE params
  //
  FDEq(float a, float b);
  
  // Constructor, populate object from console
  FDEq(void);

  // setFDEq:  udpate FDEqParams struct from arguments
  // @input: a, b. new params
  // @return
  //
  void setFDEq(float a, float b);
  
  // setFDEq:  udpate FDEqParams struct from console
  // @return
  //
  void setFDEqTerm();

  // calculateFDEroot: calculate root
  // @return:  root or error string
  //
  string calculateFDEroot();

protected:
  // isValidFDEqParams:  validate a != 0
  // @input: p, structure 
  // @return: true: valid
  //          false: invalid
  //
  bool isValidFDEqParams(FDEqParams& param) const;

  // displayFDEq:  display equation like:
  //      aX + b = 0
  // @input: param, eq parameteres
  // return:  "Equation a * X + b = 0." 
  //
  string displayFDEq() const;

private:
  FDEqParams params;
  float root;
};

#endif  // 