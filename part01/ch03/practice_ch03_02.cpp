#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::endl;
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

int p3_6_7_8 () {
  string str("asd zxc qwe");

  for (string::size_type i = 0; i < str.size(); i++) {
    auto &c = str[i];
    if (c != ' ') {
      c = 'X';
    }
  }

  cout << str << endl;

  string asdStr("hello asd");
  string::size_type j = 0;

  while (j < asdStr.size()) {
    auto &c = asdStr[j];
    if (c != ' ') {
      c = 'X';
    }
  }
  cout << asdStr << endl;
  return 0;
}

int p3_9 () {
  string s;
  cout << s[0] << endl;
  return 0;
}

int p3_10 () {
  string str = "hello, today is a good day; right?";
  string ans = "";

  for (size_t i = 0; i < str.size(); i++) {
    int c = str[i];
    if (!ispunct(c)) {
      ans += str[i];
    }
  }
  cout << ans << endl;
  return 0;
}

int p3_11 () {
  const string s = "Keep out!";
  // c 的类型是 &chart， chart 的引用
  for (auto &c : s) {
    cout << c << endl;
  }
  return 0;
}

int p3_12 () {
  vector<vector<int>> ivec; // 二维集合
  // vector<string> svec = ivec; // ❌ 不合法
  vector<string> svec(10, "null"); // 长度为 10 ，每个对象都为 "null" 的集合
  return 0;
}

int p3_13_16 () {
  vector<int> v1; // 长度 0
  cout << "v1 size: " << v1.size() << endl;

  vector<int> v2(10); // 长度 10，每个值为 0
  cout << "v2 size: " << v2.size() << endl;

  vector<int> v3(10, 42); // 长度 10，每个值为 42
  cout << "v3 size: " << v3.size() << endl;

  vector<int> v4{10}; // 长度 1，值为 10
  cout << "v4 size: " << v4.size() << endl;

  vector<int> v5{10, 42}; // 长度 2，值为 10, 42
  cout << "v5 size: " << v5.size() << endl;

  vector<string> v6{10}; // 长度 10，每个值为 空 string 对象
  cout << "v6 size: " << v6.size() << endl;

  vector<string> v7{10, "hi"}; // 长度 10，每个值为 "hi"
  cout << "v7 size: " << v7.size() << endl;

  return 0;
}

int p3_14 () {
  vector<int> inputVec;
  int intNum;
  while (cin >> intNum) {
    inputVec.push_back(intNum);
  }
  for (auto i : inputVec) {
    cout << i << endl;
  }

  return 0;
}

int p3_15 () {
  vector<string> inputVec;
  string str;
  while (cin >> str) {
    inputVec.push_back(str);
  }
  string ans = "";
  for (auto t : inputVec) {
    ans += t + ",";
  }
  cout << ans << endl;
  return 0;
}

int p3_17 () {
  vector<string> strVec;
  string str;
  while (cin >> str) {
    for (auto &w : str) {
      w = toupper(w);
    }
    strVec.push_back(str);
  }
  string ans = "";
  for (auto &word : strVec) {
    ans += word + " ";
  }
  cout << ans << endl;
  return 0;
}

int p3_18 () {
  vector<int> ivec;
  // ivec[0] = 42; ❌ 不合法
  // 修改成
  ivec.push_back(42);
  return 0;
}

int p3_19 () {
  vector<int> ivec1(10, 42);
  vector<int> ivec2{42, 42, 42, 42, 42, 42, 42, 42, 42, 42};
  vector<int> ivec3;
  while (ivec3.size() < 10) {
    ivec3.push_back(42);
  }
  return 0;
}

int p3_20 () {
  vector<int> ivec{123, 234, 456, 567, 678, 789, 890, 901};
  vector<int> reverseSumVec;
  int i = 0;
  while (i < ivec.size()) {
    cout << ivec[i] + ivec[i + 1] << ", ";
    i++;
  }

  cout << endl;

  int j = 0;
  int len = ivec.size();
  while (j < len / 2) {
    cout << ivec[j] + ivec[len - j - 1] << ", ";
    j++;
  }

  cout << endl;
  return 0;
}

int main () {
  p3_2_3();
  p3_4();
  p3_5();
  p3_6_7_8();
  p3_9();
  p3_10();
  p3_11();
  p3_12();
  p3_13_16();
  p3_14();
  p3_15();
  p3_17();
  p3_18();
  p3_19();
  p3_20();

  return 0;
}
