#ifndef StrVec_h
#define StrVec_h

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

  StrVec(StrVec &&s) noexcept : elements(s.elements), first_free(s.first_free), cap(s.cap) {
    s.elements = s.first_free = s.cap = nullptr;
  }

  StrVec &operator=(StrVec &&rhs) noexcept {
    if (this != &rhs) {
      free();
      elements = rhs.elements;
      first_free = rhs.first_free;
      cap = rhs.cap;
      rhs.elements = rhs.first_free = rhs.cap = nullptr;
    }
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
void StrVec::free() {
  if (elements) {
    for_each(first_free, elements, [](string *p) {
      alloc.destroy(p);
    });
    alloc.deallocate(elements, cap - elements);
  }
}

#endif
