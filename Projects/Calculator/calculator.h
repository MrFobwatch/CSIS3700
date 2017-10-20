//
// Created by Kevin on 10/12/2017.
//

#ifndef CALCULATOR_CALCULATOR_H
#define CALCULATOR_CALCULATOR_H

#include <cstdlib>
#include <iostream>
#include <string>
#include "fraction.h"
#include "stack.h"
#include "UnsortedDictionary.h"

class calculator {
public:
  void evaluate(string expr);
  void processSymbol(string expr, int first);
  bool hasPrecedence(char a, char b);
  void getInput();
  void doOp();



private:
  Stack<Fraction> numStack;
  Stack<char> opStack;
  UnsortedDictionary<string,Fraction> varList;

};


#endif //CALCULATOR_CALCULATOR_H
