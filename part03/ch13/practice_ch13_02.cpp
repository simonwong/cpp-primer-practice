#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

/**
 * 练习13.22：假定我们希望HasPtr的行为像一个值。
 * 即，对于对象所指向的string成员，每个对象都有一份自己的拷贝。
 * 我们将在下一节介绍拷贝控制成员的定义。
 * 但是，你已经学习了定义这些成员所需的所有知识。
 * 在继续学习下一节之前，为HasPtr编写拷贝构造函数和拷贝赋值运算符。
 */
class HasPtr {
public:
  HasPtr(const string &s = string()) : ps(new string(s)), i(0) {};
  HasPtr(const HasPtr &hp) : ps(new string(*hp.ps)), i(hp.i) {};
  HasPtr& operator=(const HasPtr &hp) {
    auto s = new string(*hp.ps);
    delete ps;
    ps = s;
    i = hp.i;
    return *this;
  };
  ~HasPtr() {
    delete ps;
  };
private:
  int i;
  string *ps;
};
void p13_22 () {
}

/**
 * 练习13.23：比较上一节练习中你编写的拷贝控制成员和这一节中的代码。
 * 确定你理解了你的代码和我们的代码之间的差异（如果有的话）。
 */
void p13_23 () {
}

/**
 * 练习13.24：如果本节中的HasPtr版本未定义析构函数，将会发生什么？
 * 如果未定义拷贝构造函数，将会发生什么？
 */
void p13_24 () {
  // 未定义析构函数：ps 将不会正确释放
  // 未定义拷贝构造函数：ps 将指向同一个指针
}

/**
 * 练习13.25：假定希望定义StrBlob的类值版本，而且希望继续使用shared_ptr，
 * 这样我们的StrBlobPtr类就仍能使用指向vector的weak_ptr了。
 * 你修改后的类将需要一个拷贝构造函数和一个拷贝赋值运算符，但不需要析构函数。
 * 解释拷贝构造函数和拷贝赋值运算符必须要做什么。解释为什么不需要析构函数。
 */
void p13_25 () {
  // 需要手动 make_shared
  // shared_ptr 会自动处理
}

/**
 * 练习13.26：对上一题中描述的StrBlob类，编写你自己的版本。
 */
void p13_26 () {
  // StrBlob(const StrBlob &sb): data (std::make_shared<blob_list>(*sb.data)) {};
  // StrBlob& operator=(const StrBlob& sb) {
  //   data = std::make_shared<blob_list>(*sb.data);
  //   return *this;
  // };
}

/**
 * 练习13.27：定义你自己的使用引用计数版本的HasPtr。
 */
class HasPtr {
public:
  HasPtr(const string &s = string()) : ps(new string(s)), i(0), use(new size_t(1)) {}
  HasPtr(const HasPtr &hp) : ps(hp.ps), i(hp.i), use(hp.use) { ++*use; }
  HasPtr& operator=(const HasPtr &hp) {
    ++*hp.use;
    if (--*use == 0) {
      delete ps;
      delete use;
    }
    ps = hp.ps;
    i = hp.i;
    use = hp.use;
    return *this;
  }
  ~HasPtr() {
    if (--*use == 0) {
      delete ps;
      delete use;
    }
  }
private:
  string *ps;
  int i;
  size_t *use;
};
void p13_27 () {
}

/**
 * 练习13.28：给定下面的类，为其实现一个默认构造函数和必要的拷贝控制成员。
 */
class TreeNode {
public:
  TreeNode() : value(string()), count(new int(1)), left(nullptr), right(nullptr) {}
  TreeNode(const TreeNode &tn) : value(tn.value), count(tn.count), left(tn.left), right(tn.right) { ++*count; }
  TreeNode& operator=(const TreeNode &tn) {
    ++*tn.count;
    if (--*count == 0) {
      delete count;
      delete left;
      delete right;
    }
    value = tn.value;
    count = tn.count;
    left = tn.left;
    right = tn.right;
    return *this;
  }
  ~TreeNode() {
    if (--*count == 0) {
      delete count;
      delete left;
      delete right;
    }
  }
private:
  string value;
  int *count;
  TreeNode *left;
  TreeNode *right;
};

class BinStrTree {
public:
  BinStrTree() : root(new TreeNode()) {}
  BinStrTree(const BinStrTree &bst) : root(new TreeNode(*bst.root)) {}
  BinStrTree& operator=(const BinStrTree &bst) {
    TreeNode *new_root = new TreeNode(*bst.root);
    delete root;
    root = new_root;
    return *this;
  }
  ~BinStrTree() {
    delete root;
  }
private:
  TreeNode *root;
};

void p13_28 () {
}

int main () {
  // p13_22();
  // p13_23();
  // p13_24();
  // p13_25();
  // p13_26();
  // p13_27();
  // p13_28();

  return 0;
}
