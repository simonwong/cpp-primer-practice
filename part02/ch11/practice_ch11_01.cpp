#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <cctype>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;

/**
 * 练习11.1：描述map和vector的不同。
 */
void p11_1 () {
  // map 是按关键字的
  // vector 是顺序的，按下标的
}

/**
 * 练习11.2：分别给出最适合使用list、vector、deque、map以及set的例子。
 */
void p11_2 () {
  // list 任意动态的双向链表
  // vector 任意动态的数组
  // deque 双端队列，软件的撤销操作、浏览器历史记录
  // map 字典单词数量统计
  // set 字典特定 exclude 的集合
}

/**
 * 练习11.3：编写你自己的单词计数程序。
 */
void p11_3 () {
  std::map<string, size_t> word_count;

  string word;

  while (cin >> word) {
    ++word_count[word];
  }

  for (const auto &w : word_count) {
    cout << w.first << " 出现 " << w.second << (w.second > 1 ? " times" : " time") << endl;
  }
}

/**
 * 练习11.4：扩展你的程序，忽略大小写和标点。例如，"example."、"example，"和"Example"应该递增相同的计数器。
 */
auto strip(string &str) -> string const& {
  for (auto &ch : str) {
    ch = std::tolower(ch);
  }
  auto rm_iter = std::remove_if(str.begin(), str.end(), ispunct);
  str.erase(rm_iter, str.end());
  return str;
};
void p11_4 () {
  std::map<string, size_t> word_count;

  string word;

  while (cin >> word) {
    ++word_count[strip(word)];
  }

  for (const auto &w : word_count) {
    cout << w.first << " 出现 " << w.second << (w.second > 1 ? " times" : " time") << endl;
  }
}

int main () {
  // p11_1();
  // p11_2();
  p11_3();
  p11_4();

  return 0;
}
