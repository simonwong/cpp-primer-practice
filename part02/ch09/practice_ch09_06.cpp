#include <iostream>
#include <string>
#include <stack>

using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::endl;
using std::stack;

/**
 * 练习9.52：使用stack处理括号化的表达式。
 * 当你看到一个左括号，将其记录下来。当你在一个左括号之后看到一个右括号，从stack中pop对象，直至遇到左括号，将左括号也一起弹出栈。
 * 然后将一个值（括号内的运算结果）push到栈中，表示一个括号化的（子）表达式已经处理完毕，被其运算结果所替代。
 */
void p9_52 () {
  string bracketedExpression = "((1+2)+(4*5))";
  stack<char> bracketedStack;
  stack<string> expressionStack;
  string tempStr = "";

  for (auto str : bracketedExpression) {
    if (str == '(') {
      bracketedStack.push(str);

      if (tempStr != "") {
        expressionStack.push(tempStr);
        tempStr = "";
      }
    } else if (str == ')') {
      if (bracketedStack.top() == '(') {
        bracketedStack.pop();

        if (tempStr != "") {
          expressionStack.push(tempStr);
          tempStr = "";
        }
      } else {
        bracketedStack.push(str);
      }
    } else {
      tempStr += str;
    }
  }
  expressionStack.push(tempStr);

  while (!expressionStack.empty()) {
    cout << expressionStack.top() << endl;
    expressionStack.pop();
  }
}

int main (int argc, char **argv) {
  p9_52();

  return 0;
}
