#include <iostream>
#include "TextQuery_27.cpp"

using std::cout;
using std::cin;
using std::endl;

void runQueries () {
  std::ifstream file("ch12_03_text.txt");

  TextQuery_27 tq(file);

  while (true) {
    cout << "输出文字查找，按 q 退出：";

    string s;

    if (!(cin >> s) || s == "q") {
      break;
    }
    print_27(cout, tq.query(s)) << endl;
  }
}

int main () {
  runQueries();

  return 0;
}
