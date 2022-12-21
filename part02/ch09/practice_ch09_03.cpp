#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <list>

using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::endl;

/**
 * 练习9.18：编写程序，从标准输入读取string序列，存入一个deque中。编写一个循环，用迭代器打印deque中的元素。
 */
void p9_18 () {
  std::deque<string> stringDeque;
  string tempStr;

  while (cin >> tempStr) {
    stringDeque.push_back(tempStr);
  }
  auto beginStart = stringDeque.begin();
  auto beginEnd = stringDeque.end();
  while (beginStart != beginEnd) {
    cout << *beginStart << endl;
    beginStart++;
  }
}

/**
 * 练习9.19：重写上题的程序，用list替代deque。列出程序要做出哪些改变。
 */
void p9_19 () {
  std::list<string> stringDeque;
  string tempStr;

  while (cin >> tempStr) {
    stringDeque.push_back(tempStr);
  }
  auto beginStart = stringDeque.begin();
  auto beginEnd = stringDeque.end();
  while (beginStart != beginEnd) {
    cout << *beginStart << endl;
    beginStart++;
  }
}

/**
 * 练习9.20：编写程序，从一个list<int>拷贝元素到两个deque中。值为偶数的所有元素都拷贝到一个deque中，而奇数值元素都拷贝到另一个deque中。
 */
void p9_20 () {
  std::list<int> numList = {1,2,3,4,5,6,6,7,8,34,56,324,47};
  std::deque<int> evenDeque;
  std::deque<int> oddDeque;
  for (auto num : numList) {
    if (num % 2 == 0) {
      evenDeque.push_back(num);
    } else {
      oddDeque.push_back(num);
    }
  }

  cout << "偶数队列：";
  for (auto item : evenDeque) {
    cout << item << ",";
  }
  cout << endl;

  cout << "奇数队列：";
  for (auto item : oddDeque) {
    cout << item << ",";
  }
  cout << endl;
}

/**
 * 练习9.21：如果我们将第308页中使用insert返回值将元素添加到list中的循环程序改写为将元素插入到vector中，分析循环将如何工作。
 */
void p9_21 () {
  std::list<string> lst;
  auto iter = lst.begin();
  string word;
  while (cin >> word) {
    iter = lst.insert(iter, word);
  }

  // 每次insert 返回被往前插入的 iter，该 iter 是就是 begin，饭后赋值给 iter，再继续循环。
}

int main (int argc, char **argv) {
  p9_18();
  p9_19();
  p9_20();
  p9_21();

  return 0;
}
