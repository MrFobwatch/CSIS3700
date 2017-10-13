//
// Created by Kevin on 10/12/2017.
//

#include "calculator.h"

bool calculator::hasPrecedence(char a, char b) {
  	if (a=='*' || a=='/')
  		return true;
  	if (b=='*' || b=='/')
  		return false;
  	if (a=='+' || a=='-')
  		return true;
  	return false;
}

void calculator::evaluate(string expr){
    numStack.clear();
    opStack.clear();
    opStack.push('$');
    int first = 0;
    string dest = "";
    
   //for(int a=0;); // Write the code to scan for =
    
    while (first<expr.length()){
        calculator.processSymbol(expr, first);
    }
    
    while (opStack.peek()!='$'){
        //perform top operation
    }
    
    if (dest != ""){
        varList.update(dest, numStack.pop())
    }
    
}

void calculator::processSymbol(string expr, int first){
    int val=0;
    string varName;
    while (first<expr.length()) {
        if (isdigit(expr[first])) {
            while (first<expr.length() && isdigit(expr[first])) {
                val=10*val + expr[first]-'0';
                first++;
                numStack.push(Fraction(val));
            }
        }

        else if (isalpha(expr[first] || expr[first]=='_')) {
            varName=expr[first];
            first++;
            while (first<expr.length() && (isalnum(expr[first] || expr[first]=='_'))) {
                varName += expr[first];
                first++;
            }
            numStack.push(varList.search(varName));
        }
    }
}

int main(int argc, char const *argv[]) {
  
  return 0;
}
