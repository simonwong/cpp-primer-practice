#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::getline;

int p3_2_3 () {
  string line;

  // getline 遇到换行符结束，结果不包含换行符
  while (getline(cin, line)) {
    cout << line << endl;
  }

  string word;

  // cin 输入会忽略空白，直到遇到下一个空白
  while (cin >> word) {
    cout << word << endl;
  }

  return 0;
}

int p3_4 () {
  string str1;
  string str2;

  cin >> str1;
  cin >> str2;

  // 判断字符串大小
  if (str1 == str2) {
    cout << "相等" << endl;
  } else {
    if (str1 > str2) {
      cout << str1 << endl;
    } else {
      cout << str2 << endl;
    }
  }

  // 判断字符串长度大小
  if (str1.size() == str2.size()) {
    cout << "长度相等" << endl;
  } else {
    if (str1.size() > str2.size()) {
      cout << str1 << endl;
    } else {
      cout << str2 << endl;
    }
  }

  return 0;
}

int p3_5 () {
  string tempStr;
  string res;

  while (cin >> tempStr) {
    res += tempStr + " ";
  }
  cout << res << endl;

  return 0;
}

int main () {
  p3_2_3();
  p3_4();
  p3_5();

  return 0;
}
