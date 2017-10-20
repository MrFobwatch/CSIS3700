//
// Created by Kevin on 10/12/2017.
//

#include "calculator.h"
using namespace std;
calculator myCalculator;

bool calculator::hasPrecedence(char a, char b) {
  	if (a=='*' || a=='/')
  		return true;
  	if (b=='*' || b=='/')
  		return false;
  	if (a=='+' || a=='-')
  		return true;
  	return false;
}

void calculator::doOp() {

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

        else if (expr[first] == '(') {
            opStack.push(expr[first]);
            first++;
        }

        else if (expr[first] == ')') {
            while (opStack.peek() != '(') {
                myCalculator.doOp();
            }
            opStack.pop();
            first++;
        }

        else if (expr[first] == ('+' || '-' || '/' || '*')) {
            while (myCalculator.hasPrecedence(opStack.peek(), expr[first])) {
                myCalculator.doOp();
            }
            opStack.push(expr[first]);
            first++;
        }

        else
            first++;
    }
}

void calculator::evaluate(string expr) {
    numStack.clear();
    opStack.clear();
    opStack.push('$');
    int first = 0;
    string dest = "";

    for(int i=0; i < expr.length(); i++) {
        if (expr[i] == '=') {
            first = i+1;
            dest; //What do I write here
        }
    }

    while (first < expr.length()){
        myCalculator.processSymbol(expr, first);
    }

    while (opStack.peek() != '$'){
        myCalculator.doOp();
    }

    if (dest != ""){
        varList.update(dest, numStack.pop());
    }
}

int main(int argc, char const *argv[]) {

  return 0;
};
