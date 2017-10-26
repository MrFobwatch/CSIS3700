//
// Created by Kevin on 10/12/2017.
//

#include "calculator.h"
//using namespace std;
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

Fraction calculator::doOp() {
    char oper = opStack.pop();
    Fraction y = numStack.pop();  //The form of the operation is x+y, x-y, etc.
    Fraction x = numStack.pop();
    if (oper == '+') {
        return(x + y);
    }

    else if (oper == '-') {
        return(x - y);
    }

    else if (oper == '*') {
        return(x * y);
    }

    else if (oper == '/') {
        return(x / y);
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

        else if (expr[first] == '(') {
            opStack.push(expr[first]);
            first++;
        }

        else if (expr[first] == ')') {
            while (opStack.peek() != '(') {
                numStack.push(myCalculator.doOp());
            }
            opStack.pop();
            first++;
        }

        else if (expr[first] == ('+' || '-' || '/' || '*')) {
            while (myCalculator.hasPrecedence(opStack.peek(), expr[first])) {
                numStack.push(myCalculator.doOp());
                first++;//I don't believe this is needed
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
            //dest; //What do I write here
        }
    }

    while (first < expr.length()){
        myCalculator.processSymbol(expr, first);
    }

    while (opStack.peek() != '$'){
        numStack.push(myCalculator.doOp());
    }

    if (dest != ""){
        varList.update(dest, numStack.pop());
    }

    std::cout << "Ans = " << numStack.peek() << endl;
}

int main(int argc, char const *argv[]) {
    string expr;
    std::cin >> expr;
    myCalculator.evaluate(expr);

    return 0;
};
