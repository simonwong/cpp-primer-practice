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

/**
 * 练习9.22：假定iv是一个int的vector，下面的程序存在什么错误？你将如何修改？
 */
void p9_22 () {
  vector<int> iv = {1,2,3,4,5,6,7};
  int some_val = 3;
  vector<int>::iterator iter = iv.begin(),
    mid = iv.begin() + iv.size() / 2;

  while (iter != mid) {
    if (*iter == some_val) {
      iv.insert(iter, 2 * some_val);
      ++iter;
    }
    ++iter;
  }
}

/**
 * 练习9.23：在本节第一个程序（第309页）中，若c.size（）为1，则val、val2、val3和val4的值会是什么？
 */
void p9_23 () {
 // 与第一个值相同
}

/**
 * 练习9.24：编写程序，分别使用at、下标运算符、front和begin提取一个vector中的第一个元素。在一个空vector上测试你的程序。
 */
void p9_24 () {
  vector<int> vi;
  cout << vi.at(0) << endl;
  cout << vi[0] << endl;
  cout << vi.front() << endl;
  cout << *(vi.begin()) << endl;
}

/**
 * 练习9.25：对于第312页中删除一个范围内的元素的程序，如果elem1与elem2相等会发生什么？
 * 如果elem2是尾后迭代器，或者elem1和elem2皆为尾后迭代器，又会发生什么？
 */
void p9_25 () {
  // 相等就不会发生什么
  // 如果是尾后迭代器，那么会删除 elem1 之后的所有元素
  // 如果都是尾后，也不会发生什么
}

/**
 * 练习9.26：使用下面代码定义的ia，将ia拷贝到一个vector和一个list中。使用单迭代器版本的erase从list中删除奇数元素，从vector中删除偶数元素。
 */
void p9_26 () {
  int ia[] = {0,1,1,2,3,5,8,13,21,55,89};
  vector<int> intVec(ia, std::end(ia));
  std::list<int> intList(ia, std::end(ia));

  auto vecBegin = intVec.begin();
  auto vecEnd = intVec.end();

  while (vecBegin != vecEnd) {
    if (*vecBegin % 2 == 0) {
      vecBegin = intVec.erase(vecBegin);
    } else {
      ++vecBegin;
    }
  }

  cout << "vector:";
  for (auto i : intVec) {
    cout << i << ",";
  }
  cout << endl;

  auto listBegin = intList.begin();
  auto listEnd = intList.end();

  while (listBegin != listEnd) {
    if (*listBegin % 2 == 1) {
      listBegin = intList.erase(listBegin);
    } else {
      ++listBegin;
    }
  }


  cout << "list:";
  for (auto i : intList) {
    cout << i << ",";
  }
  cout << endl;
}

/**
 * 练习9.27：编写程序，查找并删除forward_list<int>中的奇数元素。
 */
void p9_27 () {
  std::forward_list<int> flst = {0,1,1,2,3,5,8,13,21,55,89};
  auto prev = flst.before_begin();
  auto curr = flst.begin();

  while (curr != flst.end()) {
    if (*curr % 2 == 1) {
      curr = flst.erase_after(prev);
    } else {
      prev = curr;
      curr++;
    }
  }
}

/**
 * 练习9.28：编写函数，接受一个forward_list<string>和两个string共三个参数。
 * 函数应在链表中查找第一个string，并将第二个string插入到紧接着第一个string之后的位置。
 * 若第一个string未在链表中，则将第二个string插入到链表末尾。
 */
void findAndInsertInForwardList (std::forward_list<string> flst, string const &findStr, string const &insertStr) {
  auto prev = flst.before_begin();
  auto curr = flst.begin();

  while (curr != flst.end()) {
    if (*curr == findStr) {
      flst.insert_after(curr, insertStr);
      return;
    } else {
      prev = curr;
      curr++;
    }
  }
  flst.insert_after(prev, insertStr);
}
void p9_28 () {
  std::forward_list<string> flst = {"asd", "zxc", "ghj", "vbn", "uio", "rty"};
  findAndInsertInForwardList(flst, "zxc", "jkl");

  cout << "forward_list<string> flst: ";
  for (auto text : flst) {
    cout << text << ", ";
  }
  cout << endl;
}

int main (int argc, char **argv) {
  p9_18();
  p9_19();
  p9_20();
  p9_21();
  p9_22();
  p9_23();
  p9_24();
  p9_25();
  p9_26();
  p9_27();
  p9_28();

  return 0;
}
