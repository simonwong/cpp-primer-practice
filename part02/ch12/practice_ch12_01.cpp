#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>
#include <string>
#include <map>
#include <stdexcept>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;

/**
 * 练习12.1：在此代码的结尾，b1和b2各包含多少个元素？
 */
void p12_1 () {
  // 都包含 4 个元素
}

/**
 * 练习12.2：编写你自己的StrBlob类，包含const版本的front和back。
 */
class StrBlob {
public:
  typedef vector<string> blob_list;
  typedef blob_list::size_type size_type;

  StrBlob(): data (std::make_shared<blob_list>()) {};
  StrBlob(std::initializer_list<string> i1): data (std::make_shared<blob_list>(i1)) {};;

  size_type size() const { return data->size(); }
  bool empty() const { return data->empty(); }
  void push_back(const string &str) { data->push_back(str); }
  void pop_back() {
    check(0, "pop_back on empty StrBlob");
    return data->pop_back();
  };

  string& front () {
    check(0, "front on empty StrBlob");
    return data->front();
  }
  string& back() {
    check(0, "back on empty StrBlob");
    return data->back();
  }
  const string& front() const {
    check(0, "front on empty StrBlob");
    return data->front();
  }
  const string& back() const {
    check(0, "back on empty StrBlob");
    return data->back();
  }

private:
  std::shared_ptr<blob_list> data;

  void check(size_type i, const string &msg) const {
    if (i >= data->size()) {
      throw std::out_of_range(msg);
    }
  }
};

void p12_2 () {
}

/**
 * 练习12.3：StrBlob需要const版本的push_back和pop_back吗？如果需要，添加进去。否则，解释为什么不需要。
 */
void p12_3 () {
  // 不需要加
  // 修改指针指向的数据是合法的
}

/**
 * 练习12.4：在我们的check函数中，没有检查i是否大于0。为什么可以忽略这个检查？
 */
void p12_4 () {
  // size_type 是无符号的，确保必须大于等于 0
}

/**
 * 练习12.5：我们未编写接受一个initializer_list explicit（参见7.5.4节，第264页）参数的构造函数。讨论这个设计策略的优点和缺点。
 */
void p12_5 () {
  // explicit 防止 initializer_list 自动转换为 StrBlob
}


int main () {
  // p12_1();
  // p12_2();
  // p12_3();
  // p12_4();
  // p12_5();

  return 0;
}
