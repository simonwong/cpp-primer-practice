#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <list>
#include <algorithm>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <cctype>
#include <typeinfo>
#include <stdexcept>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::list;
using std::string;

/**
 * 练习11.37：一个无序容器与其有序版本相比有何优势？有序版本有何优势？
 */
void p11_37 () {
  // 无序容器：更为简单，性能更好
  // 有序容器：可以用来实现 OrderedVector、BinarySearchTree
}

/**
 * 练习11.38：用unordered_map重写单词计数程序（参见11.1节，第375页）
 * 和单词转换程序（参见11.3.6节，第391页）。
 */
void word_count () {
  std::unordered_map<string, size_t> word_count;

  string word;

  while (cin >> word) {
    ++word_count[word];
  }

  for (const auto &w : word_count) {
    cout << w.first << " 出现 " << w.second << (w.second > 1 ? " times" : " time") << endl;
  }
}

std::unordered_map<string, string> buildMapByUnordered_map(std::ifstream &map_file) {
  std::unordered_map<string, string> trans_map;
  string key;
  string value;

  while (map_file >> key && getline(map_file, value)) {
    if (value.size() > 1) {
      trans_map[key] = value.substr(1);
    } else {
      throw std::runtime_error("no rule for " + key);
    }
  }
  return trans_map;
}
const string &transformByUnorderedMap(const string &s, const std::unordered_map<string, string> &m) {
  auto map_it = m.find(s);
  if (map_it != m.end()) {
    return map_it->second;
  }
  return s;
}
void p11_38 () {
}

int main () {
  // p11_37();
  p11_38();

  return 0;
}
