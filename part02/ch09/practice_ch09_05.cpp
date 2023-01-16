#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>

using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::endl;

/**
 * 练习9.41：编写程序，从一个vector<char>初始化一个string。
 */
void p9_41 () {
  vector<char> vc = {'H', 'E', 'L', 'L', 'O'};

  string str(vc.cbegin(), vc.cend());

  cout << str << endl;
}

/**
 * 练习9.42：假定你希望每次读取一个字符存入一个string中，而且知道最少需要读取100个字符，应该如何提高程序的性能？
 */
void p9_42 () {
  // 使用 reserve(120)
}

/**
 * 练习9.43：编写一个函数，接受三个string参数s、oldVal和newVal。
 * 使用迭代器及insert和erase函数将s中所有oldVal替换为newVal。
 * 测试你的程序，用它替换通用的简写形式，如，将"tho"替换为"though"，将"thru"替换为"through"。
 */
void replaceString (string& s, string const& oldVal, string const& newVal) {
  for (auto cur = s.begin(); cur <= (s.end() - oldVal.size());) {
    if (oldVal == string(cur, cur + oldVal.size())) {
      cur = s.erase(cur, cur + oldVal.size());
      cur = s.insert(cur, newVal.begin(), newVal.end());
      cur += newVal.size();
    } else {
      ++cur;
    }
  }
}

void p9_43 () {
  string s = "Any text tho, and thru, tho is ok?";
  replaceString(s, "tho", "though");
  cout << s << endl;
  replaceString(s, "thru", "through");
  cout << s << endl;
}

/**
 * 练习9.44：重写上一题的函数，这次使用一个下标和replace。
 */
void replaceStringByIndex (string& s, string const& oldVal, string const& newVal) {
  for (size_t i = 0; i < s.size();) {
    if (s[i] == oldVal[0] && s.substr(i, oldVal.size()) == oldVal) {
      s.replace(i, oldVal.size(), newVal);
      i += newVal.size();
    } else {
      ++i;
    }
  }
}

void p9_44 () {
  string s = "Any text tho, and thru, tho is ok?";
  replaceString(s, "tho", "though");
  cout << s << endl;
  replaceString(s, "thru", "through");
  cout << s << endl;
}

/**
 * 练习9.45：编写一个函数，接受一个表示名字的string参数和两个分别表示前缀（如"Mr."或"Ms."）和后缀（如"Jr."或"III"）的字符串。
 * 使用迭代器及insert和append函数将前缀和后缀添加到给定的名字中，将生成的新string返回。
 */
string getPreAndAfterInsertString (string s, string const& pre, string const& after) {
  s.insert(s.begin(), pre.begin(), pre.end());
  s.append(after.begin(), after.end());

  return s;
}

void p9_45 () {
  string newStr = getPreAndAfterInsertString("Simon", "Mr.",  "III");
  cout << newStr << endl;
}

/**
 * 练习9.46：重写上一题的函数，这次使用位置和长度来管理string，并只使用insert。
 */
string getPreAndAfterInsertStringByLength (string s, string const& pre, string const& after) {
  s.insert(0, pre);
  s.insert(s.size(), after);

  return s;
}

void p9_46 () {
  string newStr = getPreAndAfterInsertString("Simon", "Mr.",  "III");
  cout << newStr << endl;
}

/**
 * 练习9.47：编写程序，首先查找string "ab2c3d7R4E6"中的每个数字字符，然后查找其中每个字母字符。
 * 编写两个版本的程序，第一个要使用find_first_of，第二个要使用find_first_not_of。
 */
void findAndPrintChartOrNumInStrBy_first_of (string const& s) {
  for (int i = 0; (i = s.find_first_of("123456789", i)) != string::npos; i++) {
    cout << s[i] << ",";
  }
  cout << endl;
  for (int i = 0; (i = s.find_first_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ", i)) != string::npos; i++) {
    cout << s[i] << ",";
  }
  cout << endl;
}
void findAndPrintChartOrNumInStrBy_first_not_of (string const& s) {
  for (int i = 0; (i = s.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ", i)) != string::npos; i++) {
    cout << s[i] << ",";
  }
  cout << endl;
  for (int i = 0; (i = s.find_first_not_of("123456789", i)) != string::npos; i++) {
    cout << s[i] << ",";
  }
  cout << endl;
}

void p9_47 () {
  findAndPrintChartOrNumInStrBy_first_of("ab2c3d7R4E6");
  findAndPrintChartOrNumInStrBy_first_not_of("ab2c3d7R4E6");
}

/**
 * 练习9.48：假定name和numbers的定义如325页所示，numbers.find（name）返回什么？
 */
void p9_48 () {
  string name("r2d2");
  string numbers("0123456789");
  cout << numbers.find(name) << endl;

  // 返回 string::npos
}

/**
 * 练习9.49：如果一个字母延伸到中线之上，如d或f，则称其有上出头部分（ascender）。
 * 如果一个字母延伸到中线之下，如p或g，则称其有下出头部分（descender）。
 * 编写程序，读入一个单词文件，输出最长的既不包含上出头部分，也不包含下出头部分的单词。
 */
void p9_49 () {
  //。。。。
}

int main (int argc, char **argv) {
  p9_41();
  // p9_42();
  p9_43();
  p9_44();
  p9_45();
  p9_46();
  p9_47();
  p9_48();
  // p9_49();

  return 0;
}
