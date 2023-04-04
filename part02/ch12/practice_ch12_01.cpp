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
  friend class StrBlobPtr;
  friend class ConstStrBlobPtr;
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

  StrBlobPtr begin();
  StrBlobPtr end();

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

/**
 * 练习12.6：编写函数，返回一个动态分配的int的vector。
 * 将此vector传递给另一个函数，这个函数读取标准输入，将读入的值保存在vector元素中。
 * 再将vector传递给另一个函数，打印读入的值。记得在恰当的时刻delete vector。
 */
vector<int>* generate_vi () {
  auto *vi = new vector<int>({ 1, 2, 3 });

  return vi;
}
vector<int> cin_vi (vector<int> *vi) {
  vector<int> temp(vi->cbegin(), vi->cend());

  return temp;
}
auto print_vi (vector<int> *vi) -> std::ostream& {
  for (auto i : *vi) {
    cout << i << ", ";
  }
  cout << endl;
  return cout;
}
void p12_6 () {
  vector<int> *vi = generate_vi();
  vector<int> temp = cin_vi(vi);
  print_vi(vi);
  delete vi;
}

/**
 * 练习12.7：重做上一题，这次使用shared_ptr而不是内置指针。
 */
using Shared_vec_int = std::shared_ptr<vector<int>>;

auto generate_vi_by_shared () {
  return std::make_shared<vector<int>>();
}
auto cin_vi_by_shared (Shared_vec_int vi) {
  vector<int> temp(vi->cbegin(), vi->cend());

  return temp;
}
auto print_vi_by_shared (Shared_vec_int vi) -> std::ostream& {
  for (auto i : *vi) {
    cout << i << ", ";
  }
  cout << endl;
  return cout;
}
void p12_7 () {
  Shared_vec_int vi = generate_vi_by_shared();
  auto temp = cin_vi_by_shared(vi);
  print_vi_by_shared(vi);
}

/**
 * 练习12.8：下面的函数是否有错误？如果有，解释错误原因。
 */
void p12_8 () {
  // p 会被转正 bool 类型，导致内存没有被释放
}

/**
 * 练习12.9：解释下面代码执行的结果
 */
void p12_9 () {
  int *q = new int(32), *r = new int(100);
  r = q; // r 指针指向 q，原来的 r 内存没有被释放
  auto q2 = std::make_shared<int>(42), r2 = std::make_shared<int>(100);
  r2 = q2; // r2 指针指向 q2，原来的 r2 内存自动释放
}

/**
 * 练习12.10：下面的代码调用了第413页中定义的process函数，解释此调用是否正确。如果不正确，应如何修改？
 */
void process(std::shared_ptr<int> ptr) {
  cout << "inside the process function:" << ptr.use_count() << "\n";
}
void p12_10 () {
  std::shared_ptr<int> p(new int(32));
  process(std::shared_ptr<int>(p));

  cout << p.use_count() << endl;
  auto q = p;
  cout << p.use_count() << endl;
  cout << *p << endl;
}

/**
 * 练习12.11：如果我们像下面这样调用process，会发生什么？
 */
void p12_11 () {
  std::shared_ptr<int> p(new int(32));
  process(std::shared_ptr<int>(p.get()));
}

/**
 * 练习12.12：p和q的定义如下，对于接下来的对process的每个调用，如果合法，解释它做了什么，如果不合法，解释错误原因
 */
void p12_12 () {
  auto p = new int();
  auto sp = std::make_shared<int>();

  // a
  process(sp);
  // b
  // process(new int()); // ❌ 不合法，process 接收 shared_ptr 类型
  // c
  // process(p); // ❌ 不合法，process 接收 shared_ptr 类型
  // d // 不是一个好的实践
  process(std::shared_ptr<int>(p));
}

/**
 * 练习12.13：如果执行下面的代码，会发生什么？
 */
void p12_13 () {
  auto sp = std::make_shared<int>();
  auto p = sp.get();
  // delete p; 运行时错误
}

/**
 * 练习12.14：编写你自己版本的用shared_ptr管理connection的函数。
 */
struct destination {};
struct connection {};
connection connect(destination*);
void disconnect(connection);

void end_connection(connection *p) {
  disconnect(*p);
}

void p12_14 () {
  destination d = destination();
  connection c = connect(&d);
  std::shared_ptr<connection> p(&c, end_connection);
}
/**
 * 练习12.15：重写第一题的程序，用lambd（a参见10.3.2节，第346页）代替end_connection函数。
 */
void p12_15 () {
  destination d = destination();
  connection c = connect(&d);
  std::shared_ptr<connection> p(&c, [](connection *p) {
    disconnect(*p);
  });
}

/**
 * 练习12.16：如果你试图拷贝或赋值unique_ptr，编译器并不总是能给出易于理解的错误信息。
 * 编写包含这种错误的程序，观察编译器如何诊断这种错误。
 */
void p12_16 () {
  auto pi = std::unique_ptr<int>(new int(12));
  // auto c = pi;
  // auto c(pi);
}

/**
 * 练习12.17：下面的unique_ptr声明中，哪些是合法的，哪些可能导致后续的程序错误？解释每个错误的问题在哪里。
 */
void p12_17 () {
  int ix = 1024, *pi = &ix, *pi2 = new int(2048);
  typedef std::unique_ptr<int> IntP;

  // a
  // IntP p0(ix); // ❌ ix 不是指针类型的

  // b
  IntP p1(pi); // ❌ 必须是 new 分配的

  // c
  IntP p2(pi2); // ❌

  // d
  IntP p3(&ix); // ❌ 同 b

  // e
  IntP p4(new int(2048)); // ✅

  // f
  IntP p5(p2.get()); // ❌
}

/**
 * 练习12.18：shared_ptr为什么没有release成员？
 */
void p12_18 () {
  // 因为其他指向对象的  shared_ptr 也可以删除
}

/**
 * 练习12.19：定义你自己版本的StrBlobPtr，更新StrBlob类，加入恰当的friend声明及begin和end成员。
 */
class StrBlobPtr {
public:
  StrBlobPtr(): curr(0) {}
  StrBlobPtr(StrBlob &a, std::size_t sz = 0): wptr(a.data), curr(0) {}
  bool operator!=(StrBlobPtr& p) { return p.curr != curr; }
  string& deref() const {
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
  };
  StrBlobPtr& incr() {
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
  };

private:
  std::shared_ptr<vector<string>> check(std::size_t i, const string &msg) const {
    auto ret = wptr.lock();
    if (!ret) {
      throw std::runtime_error("unbound StrBlobPtr");
    }
    if (i >= ret->size()) {
      throw std::out_of_range(msg);
    }
    return ret;
  };
  std::weak_ptr<vector<string>> wptr;
  std::size_t curr;
};

StrBlobPtr StrBlob::begin() {
  return StrBlobPtr(*this);
}

StrBlobPtr StrBlob::end() {
  auto ret = StrBlobPtr(*this, data->size());
  return ret;
}

void p12_19 () {
}

/**
 * 练习12.20：编写程序，逐行读入一个输入文件，将内容存入一个StrBlob中，用一个StrBlobPtr打印出StrBlob中的每个元素。
 */
void p12_20 () {
  StrBlob strb({ "sad", "cvb" });
  StrBlobPtr beg(strb.begin()), end(strb.end());

  while (beg != end) {
    cout << beg.deref() << endl;
    beg.incr();
  }
}

/**
 * 练习12.21：也可以这样编写StrBlobPtr的deref成员
 */
void p12_21 () {
  // std::string& deref() const {
  //   return (*check(curr, "dereference past end"))[curr];
  // }
  //
  // 这样写不容易看
}

/**
 * 练习12.22：为了能让StrBlobPtr使用const StrBlob，你觉得应该如何修改？定义一个名为ConstStrBlobPtr的类，使其能够指向const StrBlob。
 */
class ConstStrBlobPtr {
public:
  ConstStrBlobPtr(): curr(0) {}
  ConstStrBlobPtr(const StrBlob &a, std::size_t sz = 0): wptr(a.data), curr(0) {}
  bool operator!=(ConstStrBlobPtr& p) { return p.curr != curr; }
  string& deref() const {
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
  };
  ConstStrBlobPtr& incr() {
    check(curr, "increment past end of ConstStrBlobPtr");
    ++curr;
    return *this;
  };

private:
  std::shared_ptr<vector<string>> check(std::size_t i, const string &msg) const {
    auto ret = wptr.lock();
    if (!ret) {
      throw std::runtime_error("unbound ConstStrBlobPtr");
    }
    if (i >= ret->size()) {
      throw std::out_of_range(msg);
    }
    return ret;
  };
  std::weak_ptr<vector<string>> wptr;
  std::size_t curr;
};
void p12_22 () {
}

int main () {
  // p12_1();
  // p12_2();
  // p12_3();
  // p12_4();
  // p12_5();
  p12_6();
  p12_7();
  // p12_8();
  // p12_9();
  p12_10();
  p12_11();
  p12_12();
  p12_13();
  // p12_14();
  // p12_15();
  p12_16();
  // p12_17();
  // p12_18();
  // p12_19();
  p12_20();
  // p12_21();
  // p12_22();

  return 0;
}
