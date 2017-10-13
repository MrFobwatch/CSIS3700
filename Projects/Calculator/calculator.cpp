//
// Created by Kevin on 10/12/2017.
//

#include "calculator.h"
int main(int argc, char const *argv[]) {
  string expr;
  int val,i=0;
  string varName;

  while (i<expr.length()) {
    	if (isdigit(expr[i])) {
        val=0;
        while (i<expr.length() && isdigit(expr[:])) {
          val=10*val + expr[i]-'0';
  		    i++;
  		  }
        numStack.push(Fraction(val));
      }

      else if (isalpha(expr[i] || expr[i]='_') {
        varName=expr[i];
        i++;
        while (i<expr.length() && (isalnum(expr[i] || expr[i]=='_')) {
          varName += expr[i];
          i++;
        }
        numStack.push(varList.search(varName));
      }
    }

  bool hasPrecedence(char a, char b) {
  	if (a=='*' || a=='/')
  		return true;
  	if (b=='*' || b=='/')
  		return false;
  	if (a=='+' || a=='-')
  		return true;
  	return false;
  	}
  return 0;
}
