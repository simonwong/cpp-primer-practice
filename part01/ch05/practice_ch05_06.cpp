#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::endl;
using std::getline;

/**
 * 练习5.23：编写一段程序，从标准输入读取两个整数，输出第一个数除以第二个数的结果。
 *
 * 练习5.24：修改你的程序，使得当第二个数是0时抛出异常。先不要设定catch子句，运行程序并真的为除数输入0，看看会发生什么？
 *
 * 练习5.25：修改上一题的程序，使用try语句块去捕获异常。catch子句应该为用户输出一条提示信息，询问其是否输入新数并重新执行try语句块的内容。
 */
int p5_23_24_25 () {
  int n1, n2;

  while (cin >> n1 >> n2) {
    try {
      cout << n1 / n2 << endl;
    } catch(std::runtime_error e) {
      std::cerr << e.what() << endl;
    }
  }

  return 0;
}

int main () {
  p5_23_24_25();

  return 0;
}
