#include <iostream>
#include <string>
#include <vector>
#include <set>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

/**
 * 练习13.29：解释swap（HasPtr&，HasPtr&）中对swap的调用不会导致递归循环。
 */
void p13_29 () {
  // 后续的 swap 使用的是 标准库的 swap
}


/**
 * 练习13.30：为你的类值版本的HasPtr编写swap函数，并测试它。为你的 swap 函数添加一个打印语句，指出函数什么时候执行。
 */
class HasPtr {
  friend void swap(HasPtr&, HasPtr&);
  friend bool operator<(const HasPtr&, const HasPtr&);
public:
  HasPtr(const string &s = string()) : ps(new string(s)), i(0) {};
  HasPtr(const HasPtr &hp) : ps(new string(*hp.ps)), i(hp.i) {};
  HasPtr& operator=(HasPtr hp) {
    this->swap(hp);
    return *this;
  };
  void swap (HasPtr &rhp) {
    using std::swap;
    swap(ps, rhp.ps);
    swap(i, rhp.i);
    cout << "swap after" << endl;
    cout << "this.ps: " << *ps << endl;
    cout << "rhp.ps: " << *rhp.ps << endl;
  }

  ~HasPtr() {
    delete ps;
  };

  void show () {
    cout << *ps << endl;
  }
private:
  int i;
  string *ps;
};

void swap(HasPtr& lhs, HasPtr& rhs) {
  lhs.swap(rhs);
}

void p13_30 () {
  HasPtr lhp("ASD");
  HasPtr rhp("ZXC");

  swap(lhp, rhp);
}

/**
 * 练习13.31：为你的HasPtr类定义一个<运算符，并定义一个HasPtr的vector。
 * 为这个vector添加一些元素，并对它执行sort。注意何时会调用swap。
 */
bool operator<(const HasPtr &lhp, const HasPtr &rhp) {
  return *lhp.ps < *rhp.ps;
}
void p13_31 () {
  HasPtr a("H"), b("E"), c("L"), d("L"), e("O");
  vector<HasPtr> vec{a,b,c,d,e};
  std::sort(vec.begin(), vec.end());

  for (auto elem : vec) {
    elem.show();
  }
}


/**
 * 练习13.32：类指针的HasPtr版本会从swap函数受益吗？如果会，得到了什么益处？如果不是，为什么？
 */
void p13_32 () {
  // 避免内存分配才能提高性能，类指针版本没有受益
}

/**
 * 练习13.33：为什么Message的成员save和remove的参数是一个Folder&？为什么我们不将参数定义为Folder或是const Folder&？
 */
void p13_33 () {
  // 因为 folder 是可变的，所以要指向指针
}

/**
 * 练习13.34：编写本节所描述的Message。
 */
class Message {
  friend Folder;
  friend void swap(Message &lhs, Message &rhs);
public:
  explicit Message(const string &str = "") : contents(str) {};
  Message(const Message &m) : contents(m.contents), folders(m.folders) {
    add_to_Folders(m);
  };
  Message& operator=(const Message &rhs) {
    remove_from_Folders();
    contents = rhs.contents;
    folders = rhs.folders;
    add_to_Folders(rhs);
    return *this;
  };
  ~Message() {
    remove_from_Folders();
  };
  void save(Folder &f) {
    folders.insert(&f);
    f.addMsg(this);
  };
  void remove(Folder &f) {
    folders.erase(&f);
    f.removeMsg(this);
  };
private:
  string contents;
  std::set<Folder*> folders;

  void add_to_Folders(const Message &m) {
    for (auto f : m.folders) {
      f->addMsg(this);
    }
  };
  void remove_from_Folders() {
    for (auto f : folders) {
      f->removeMsg(this);
    }
  };
};

void swap(Message &lhs, Message &rhs) {
  using std::swap;

  for (auto f : lhs.folders) {
    f->removeMsg(&lhs);
  }
  for (auto f : rhs.folders) {
    f->removeMsg(&rhs);
  }

  swap(lhs.folders, rhs.folders);
  swap(lhs.contents, rhs.contents);

  for (auto f : lhs.folders) {
    f->addMsg(&lhs);
  }
  for (auto f : rhs.folders) {
    f->addMsg(&rhs);
  }
}

class Folder {
public:
  void addMsg (Message*);
  void removeMsg (Message*);
};

void p13_34 () {
}

int main () {
  // p13_29();
  p13_30();
  p13_31();
  // p13_32();
  // p13_33();
  // p13_34();

  return 0;
}
