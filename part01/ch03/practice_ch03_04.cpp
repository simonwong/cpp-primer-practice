#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::endl;
using std::getline;

int p3_21_22 () {
  // 21 没看懂，不过都是使用迭代器遍历罢了
  string str = "hello iterator";
  auto start = str.begin();

  while (!isspace(*start) && start != str.end()) {
    *start = toupper(*start);
    start++;
  }

  cout << str << endl;

  return 0;
}

int p3_23 () {
  vector<int> intVec = {12, 123, 23, 54, 4, 78, 3, 56, 90, 10};

  auto start = intVec.begin();
  while (start != intVec.end()) {
    *start = *start * 2;
    cout << *start << endl;
    start++;
  }

  return 0;
}

int p3_24 () {
  vector<int> ivec{123, 234, 456, 567, 678, 789, 890, 901};
  vector<int> reverseSumVec;
  auto start = ivec.begin();
  while (start != ivec.end() - 1) {
    cout << *start + *(start + 1) << ", ";
    start++;
  }

  cout << endl;

  start = ivec.begin();
  auto end = ivec.end() - 1;

  while (start < end) {
    cout << *start + *end << ", ";
    start++;
    end--;
  }

  cout << endl;
  return 0;
}

int p3_25 () {
  vector<unsigned> scores(11, 0);
  vector<unsigned> grade{13, 42, 56, 68, 75, 77, 76, 85, 95, 100, 7};
  auto start = grade.begin();
  while (start != grade.end()) {
    if (*start <= 100) {
      int idx = *start / 10;
      *(scores.begin() + idx) += 1;
    }
    start++;
  }

  return 0;
}

int p3_26 () {
  // 迭代器之间只能 - ，不能 +，相减后的值，可以相加
  // mid = beg + （end - beg） / 2
  // mid = （beg + end） / 2
  vector<unsigned> scores{12, 23, 45, 56, 58, 68, 79, 88, 89, 90, 102};
  auto beg = scores.begin();
  auto end = scores.end() - 1;

  int findInt = 45;
  vector<unsigned>::iterator ans;

  while (beg <= end) {
    auto mid = beg + (end - beg) / 2;
    cout << *mid << endl;
    if (findInt < *mid) {
      end = mid - 1;
    } else if (findInt > *mid) {
      beg = mid + 1;
    } else {
      ans = mid;
      break;
    }
  }

  cout << *ans << endl;

  return 0;
}

int txt_size() {
  return 1;
}

int p3_27 () {
  unsigned buf_size = 1024;
  // a
  int ia[buf_size]; // ❌ 不合法 buf_size 必须是常量
  // b
  int ib[4 * 7 - 14]; // 合法
  // c
  int ic[txt_size()]; // ❌ 不合法, txt_size() 的结果需要在运行时才能知道
  // d
  // char st[11] = "fundamental"; ❌ 不合法，需要考虑字符串最后的空字符，长度应该为 12

  return 0;
}

int p3_28 () {
  // string sa[10]; // 全是空字符串
  // int ia[10]; // 全是 0
  // int main () {
  //   string sa2[10]; // 全是空字符串
  //   int ia2[10]; // 全是未定义
  // }

  return 0;
}

int p3_29 () {
  // 数组的缺点
  // 1. 必须要预先知道长度
  // 2. 不能随意增加元素
  // 3. 不允许拷贝和赋值
  return 0;
}

int p3_30_31 () {
  constexpr size_t array_size = 10;
  int ia[array_size];
  //                  ix <= array_size <= 会溢出
  for (size_t ix = 0; ix < array_size; ix++) {
    ia[ix] = ix;
  }

  return 0;
}

int p3_32 () {
  // 数组拷贝
  constexpr size_t size = 10;
  int ia_origin[size] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
  int ia_copy[size];

  for (size_t i = 0; i < size; i++) {
    ia_copy[i] = ia_origin[i];
  }

  // vector 拷贝
  vector<int> iv_origin = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
  vector<int> iv_copy(iv_origin);

  return 0;
}

int p3_33 () {
  // 不初始化，数组的元素将都会为未定义
  return 0;
}

int p3_34 () {
  // p1 += p2 - p1
  // p2 - p1 得到差值，然后 p1 加上差值。
  // 实际上就只 p1 指针移动到 p2 指针位置。
  // 怎样都会合法
  return 0;
}

int p3_35 () {
  int arr[] = {1, 2, 3, 4, 5, 6, 7};

  for (auto i = std::begin(arr); i != std::end(arr); i++) {
    *i = 0;
  }
  for (auto i : arr) {
    cout << i << endl;
  }

  return 0;
}


int main () {
  p3_21_22();
  p3_23();
  p3_24();
  p3_25();
  p3_26();
  p3_27();
  // p3_28();
  // p3_29();
  p3_30_31();
  p3_32();
  // p3_33();
  // p3_34();
  p3_35();
  p3_36();

  return 0;
}
