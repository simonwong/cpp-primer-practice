#include <iostream>
#include <string>
#include <vector>
#include "Screen_23_24.h"
#include "Screen_27.h"

using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::endl;
using std::getline;
using std::initializer_list;

/**
 * 练习7.34：如果我们把第256页Screen类的pos的typedef放在类的最后一行会发生什么情况？
 */
void p7_34 () {
  // 未知的名字 pos
}

/**
 * 练习7.35：解释下面代码的含义，说明其中的Type和initVal分别使用了哪个定义。如果代码存在错误，尝试修改它。
 */
typedef string Type;
Type initial(); // string
class Exercise {
public:
  typedef double Type;
  Type setVal(Type); // double
  Type initVal(); // double
private:
  int val;
};
// Type Exercise::setVal(Type parm) { // string double
//   val = parm + initVal(); // Exercise::initVal
//   return val;
// }
Exercise::Type Exercise::setVal(Type parm) {
  val = parm + initVal();
  return val;
}

void p7_35 () {
}



int main () {
  // p7_34();
  // p7_35()

  return 0;
}
