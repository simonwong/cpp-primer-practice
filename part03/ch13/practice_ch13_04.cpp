#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <memory>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

class StrVec {
public:
  StrVec(): elements(nullptr), first_free(nullptr), cap(nullptr) {}

  StrVec(std::initializer_list<string> listStr): elements(nullptr), first_free(nullptr), cap(nullptr) {
    auto newData = alloc_n_copy(listStr.begin(), listStr.end());
    elements = newData.first;
    first_free = newData.second;
  }

  StrVec(const StrVec &s) {
    auto newData = alloc_n_copy(s.begin(), s.end());
    elements = newData.first;
    first_free = newData.second;
  }

  StrVec &operator=(const StrVec &rhs) {
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
  }

  ~StrVec() {
    free();
  }

  void push_back(const string &s) {
    chk_n_alloc();
    alloc.construct(first_free++, s);
  };

  size_t size() const {
    return first_free - elements;
  }

  size_t capacity () const {
    return cap - elements;
  }

  string *begin() const {
    return elements;
  }

  string *end() const {
    return first_free;
  }

private:
  static std::allocator<string> alloc;

  void chk_n_alloc () {
    if (size() == capacity()) {
      reallocate();
    }
  }

  std::pair<string*, string*> alloc_n_copy(const string*b, const string*e) {
    auto data = alloc.allocate(e - b);
    return {
      data,
      std::uninitialized_copy(b, e, data),
    };
  }
  void free() {
    if (elements) {
      for (auto p = first_free; p != elements; ) {
        alloc.destroy(--p);
      }
      alloc.deallocate(elements, cap - elements);
    }
  }
  void reallocate() {
    auto newCapacity = size() ? 2 * size() : 1;
    auto newData = alloc.allocate(newCapacity);

    auto dest = newData;
    auto elem = elements;
    for (size_t i = 0; i != size(); ++i) {
      alloc.construct(dest++, std::move(*elem++));
    }
    free();
    elements = newData;
    first_free = dest;
    cap = elements + newCapacity;
  };
  string *elements;
  string *first_free;
  string *cap;
};

/**
 * 练习13.39：编写你自己版本的StrVec，包括自己版本的reserve、capacity（参见9.4节，第318页）和resize（参见9.3.5节，第314页）。
 */
void p13_39 () {
}

/**
 * 练习13.40：为你的StrVec类添加一个构造函数，它接受一个initializer_list<string>参数。
 */
void p13_40 () {
}

/**
 * 练习13.41：在push_back中，我们为什么在construct调用中使用前置递增运算？如果使用后置递增运算的话，会发生什么？
 */
void p13_41 () {
  // first_free 表示值的下一个指针，使用后置那么就会留空一个
}

/**
 * 练习13.42：在你的TextQuery和QueryResult类（参见12.3节，第431页）中用你的StrVec类代替vector<string>，以此来测试你的StrVec类。
 */
void p13_42 () {
}

/**
 * 练习13.43：重写free成员，用for_each和lambda（参见10.3.2节，第346页）来代替for循环destroy元素。你更倾向于哪种实现，为什么？
 */
void StrVec::free() {
  if (elements) {
    for_each(first_free, elements, [](string *p) {
      alloc.destroy(p);
    });
    alloc.deallocate(elements, cap - elements);
  }
}
void p13_43 () {
  // 写 for_each + lambda 表达式更加简洁
}

/**
 * 练习13.44：编写标准库string类的简化版本，命名为String。
 * 你的类应该至少有一个默认构造函数和一个接受C风格字符串指针参数的构造函数。
 * 使用allocator为你的String类分配所需内存。
 */

class String {
public:
  String(): elements(nullptr), first_free(nullptr), cap(nullptr) {}

  String(std::initializer_list<char> listStr): elements(nullptr), first_free(nullptr), cap(nullptr) {
    auto newData = alloc_n_copy(listStr.begin(), listStr.end());
    elements = newData.first;
    first_free = newData.second;
  }

  String(const String &s) {
    auto newData = alloc_n_copy(s.begin(), s.end());
    elements = newData.first;
    first_free = newData.second;
  }

  String &operator=(const String &rhs) {
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
  }

  ~String() {
    free();
  }

  void push_back(const char &s) {
    chk_n_alloc();
    alloc.construct(first_free++, s);
  };

  size_t size() const {
    return first_free - elements;
  }

  size_t capacity () const {
    return cap - elements;
  }

  char *begin() const {
    return elements;
  }

  char *end() const {
    return first_free;
  }

private:
  static std::allocator<char> alloc;

  void chk_n_alloc () {
    if (size() == capacity()) {
      reallocate();
    }
  }

  std::pair<char*, char*> alloc_n_copy(const char*b, const char*e) {
    auto data = alloc.allocate(e - b);
    return {
      data,
      std::uninitialized_copy(b, e, data),
    };
  }
  void free() {
    if (elements) {
      for (auto p = first_free; p != elements; ) {
        alloc.destroy(--p);
      }
      alloc.deallocate(elements, cap - elements);
    }
  }
  void reallocate() {
    auto newCapacity = size() ? 2 * size() : 1;
    auto newData = alloc.allocate(newCapacity);

    auto dest = newData;
    auto elem = elements;
    for (size_t i = 0; i != size(); ++i) {
      alloc.construct(dest++, std::move(*elem++));
    }
    free();
    elements = newData;
    first_free = dest;
    cap = elements + newCapacity;
  };
  char *elements;
  char *first_free;
  char *cap;
};
void p13_44 () {
}

int main () {
  // p13_39();
  // p13_40();
  // p13_41();
  // p13_42();
  // p13_43();
  // p13_44();

  return 0;
}
