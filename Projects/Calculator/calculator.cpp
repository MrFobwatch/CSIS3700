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

    else
        return 0;

}

void calculator::processSymbol(string expr, int first){
    int val=0;
    string varName = "";
    while (first<expr.length()) {
        if (isdigit(expr[first])) {
            val=0;
            while (isdigit(expr[first])) {
                val=10*val + expr[first]-'0';
                first++;
            }
            numStack.push(Fraction(val));
            first++;
        }

        else if (isalpha(expr[first]) || expr[first]=='_') {
            //std::cout << "/* expr = alpha*/" << '\n';
            while (first<expr.length() && (isalnum(expr[first]) || expr[first]=='_')) {
                varName += expr[first];
                first++;
            }
            //std::cout << "varName: " << varName << '\n';
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

        else if (expr[first] == '+' || expr[first] == '-' || expr[first] == '/' || expr[first] == '*') {
            while (myCalculator.hasPrecedence(opStack.peek(), expr[first])) {
                numStack.push(myCalculator.doOp());
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
    int first =  0;
    string dest = "";

    for(int i=first; i < expr.length(); i++) {
        if (expr[i] == '=') {
            //std::cout << "/* expr = */" << '\n';
            first = i+1;
            int destIndex = 0;
            while (destIndex<expr.length() && (isalnum(expr[destIndex]) || expr[destIndex]=='_')) {
                //std::cout << "Dest +=" << std::endl;
                dest += expr[destIndex];
                destIndex++;
            }
        }
    }

    myCalculator.processSymbol(expr, first);

    while (opStack.peek() != '$'){
        numStack.push(myCalculator.doOp());
    }

    if (dest != ""){
        //std::cout << "varList updated" << '\n';
        //std::cout << "dest:" << dest << std::endl;
        varList.insert(dest, numStack.peek());
    }

    std::cout << "Ans = " << numStack.peek() << endl;
}

int main(int argc, char const *argv[]) {
    string expr;
    std::cin >> expr;
    myCalculator.evaluate(expr);
    std::cin >> expr;
    myCalculator.evaluate(expr);

    return 0;
};
