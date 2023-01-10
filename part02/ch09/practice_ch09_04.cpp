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
 * 练习9.35：解释一个vector的capacity和size有何区别。
 */
void p9_35 () {
  // size 是当前容器的所占的元素数目
  // capacity 是当前容器还剩多少个元素数目可以放
}

/**
 * 练习9.36：一个容器的capacity可能小于它的size吗？
 */
void p9_36 () {
  // 不可能
}

/**
 * 练习9.37：为什么list或array没有capacity成员函数？
 */
void p9_37 () {
  // list 不是连续空间
  // array 是固定的空间
}

/**
 * 练习9.38：编写程序，探究在你的标准库实现中，vector是如何增长的。
 */
void p9_38 () {
  vector<int> vi;
  cout << "vi size: " << vi.size() << ", capacity: " << vi.capacity() << endl;
  vi.push_back(1);
  cout << "vi size: " << vi.size() << ", capacity: " << vi.capacity() << endl;
  for (size_t i = 0; i < 9; i++) {
    vi.push_back(1);
  }
  cout << "vi size: " << vi.size() << ", capacity: " << vi.capacity() << endl;
  for (size_t i = 0; i < 52; i++) {
    vi.push_back(1);
  }
  cout << "vi size: " << vi.size() << ", capacity: " << vi.capacity() << endl;
  vi.push_back(1);
  vi.push_back(1);
  cout << "vi size: " << vi.size() << ", capacity: " << vi.capacity() << endl;
}

/**
 * 练习9.39：解释下面程序片段做了什么：
 */
void p9_39 () {
  vector<string> svec;
  svec.reserve(1024); // 申请大小扩冲到 1024
  cout << "svec size: " << svec.size() << ", capacity: " << svec.capacity() << endl;

  string word = "Hello";
  for (size_t i = 0; i < 1000; i++) {
    svec.push_back(word);
  }
  cout << "svec size: " << svec.size() << ", capacity: " << svec.capacity() << endl;

  svec.resize(svec.size() + svec.size() / 2); // 操作没有做成功
  cout << "svec size: " << svec.size() << ", capacity: " << svec.capacity() << endl;
}

/**
 * 练习9.40：如果上一题中的程序读入了256个词，在resize之后容器的capacity可能是多少？如果读入了512个、1000个或1048个词呢？
 */
void p9_40 () {
  // 256： 384 1024
  // 512：768 1024
  // 1000：1500 2048
  // 1048：1572 2048
}

int main (int argc, char **argv) {
  // p9_35();
  // p9_36();
  // p9_37();
  p9_38();
  p9_39();
  // p9_40();

  return 0;
}
