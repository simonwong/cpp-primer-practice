#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include "Sales_data.h"

using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::endl;

/**
 * 练习8.9：使用你为8.1.2节（第281页）第一个练习所编写的函数打印一个istringstream对象的内容。
 */
std::istream& getInStream (std::istream& in) {
  string str;
  while (in >> str) {
    cout << str << endl;
  }
  cin.clear();

  return in;
}
void p8_09 () {
  std::istringstream iss("Hello");
  getInStream(iss);
}

/**
 * 练习8.10：编写程序，将来自一个文件中的行保存在一个vector<string>中。然后使用一个istringstream从vector读取数据元素，每次读取一个单词。
 */
void p8_10 () {
  std::ifstream inputFile("personInfo.txt");
  vector<string> txtLines;

  if (!inputFile) {
    std::cerr << "No data" << endl;
    return;
  }

  string row;
  while (getline(inputFile, row)) {
    txtLines.push_back(row);
  }

  for (auto &row : txtLines) {
    std::istringstream iss(row);
    string word;

    while (iss >> word) {
      cout << word << endl;
    }
  }
}

/**
 * 练习8.11：本节的程序在外层while循环中定义了istringstream对象。
 * 如果record对象定义在循环之外，你需要对程序进行怎样的修改？重写程序，将record的定义移到while循环之外，验证你设想的修改方法是否正确。
 */
struct PersonInfo {
  string name;
  vector<string> phones;
};

vector<PersonInfo> getPersonInfoList (std::istream &inputFile) {
  string line, word;
  vector<PersonInfo> people;
  std::istringstream record;

  while (getline(inputFile, line)) {
    PersonInfo info;
    record.clear();
    record.str(line);
    record >> info.name;
    while (record >> word) {
      info.phones.push_back(word);
    }
    people.push_back(info);
  }

  return people;
}

vector<PersonInfo> p8_11 () {
  std::ifstream inputFile("personInfo.txt");

  if (!inputFile) {
    std::cerr << "No data" << endl;
    return {};
  }

  return getPersonInfoList(inputFile);
}

/**
 * 练习8.12：我们为什么没有在PersonInfo中使用类内初始化？
 */
void p8_12 () {
  // 希望 PersonInfo 是个聚合类，所以不需要类内初始化
}

/**
 * 练习8.13：重写本节的电话号码程序，从一个命名文件而非cin读取数据。
 */
bool valid (const string & phone) {
  if (phone.size() == 11) {
    return true;
  }
  return false;
}
string format (const string & phone) {
  return phone;
}
void p8_13 () {
  vector<PersonInfo> people = p8_11();

  for (const auto &entry : people) {
    std::ostringstream formatted, badNums;

    for (const auto &nums : entry.phones) {
      if (!valid(nums)) {
        badNums << " " << nums;
      } else {
        formatted << " " << format(nums);
      }
    }

    if (badNums.str().empty()) {
      cout << entry.name << " " << formatted.str() << endl;
    } else {
      std::cerr << "input err：" << entry.name
        << " invalid number(s) " << badNums.str() << endl;
    }
  }
}

/**
 * 练习8.14：我们为什么将entry和nums定义为const auto&？
 */
void p8_14 () {
  // 都是类类型，不是内置类型，所以使用引用
  // 因为不需要修改内容，只读就行
}

int main (int argc, char **argv) {
  p8_09();
  p8_10();
  p8_11();
  // p8_12();
  p8_13();
  p8_14();

  return 0;
}
