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

int p3_36 () {
  // 判断两个数组是否相等
  int arr_1[] = {1, 2, 3, 4, 5, 6, 7};
  int arr_2[] = {1, 2, 3, 4, 5, 6, 7};

  auto start_1 = std::begin(arr_1);
  auto end_1 = std::end(arr_1);
  auto start_2 = std::begin(arr_2);
  auto end_2 = std::end(arr_2);

  while (start_1 != end_1 && start_2 != end_2) {
    cout << *start_1 << *start_2 << endl;
    if (*start_1 == *start_2) {
      start_1++;
      start_2++;
    } else {
      cout << "数组不相等" << endl;
      return -1;
    }
  }
  cout << "数组相等" << endl;

  // 判断两个 vector 是否相等
  vector<int> vec_1 = {1, 2, 3, 4, 5, 6, 7};
  vector<int> vec_2 = {1, 2, 3, 4, 5, 6, 7};

  if (vec_1 == vec_2) {
    cout << "vector 不相等" << endl;
    return -1;
  }

  cout << "vector 相等" << endl;

  return 0;
}

int p3_37 () {
  const char ca[] = {'h', 'e', 'l', 'l', '0'};
  const char *cp = ca; // 得到 ca 第一个元素的指针
  while (*cp) {
    cout << *cp << endl; // 打印 'h'
    ++cp; // 因为没有空字符串，所以不会停止循环
  }

  return 0;
}

int p3_38 () {
  // 两个指针相加很可能会超出范围

  // 两只指针相减得到指针距离
  // 指针加一个整数，即移动 n 位
  // 两指针相加没有现实意义

  return 0;
}

int p3_39 () {
  string strA = "hello";
  string strB = "hello";

  // 比较 string 对象
  if (strA == strB) {
    cout << "string 对象 相等" << endl;
  } else {
    cout << "string 对象 不相等" << endl;
  }

  // 比较 c 风格字符串内容
  char cStrA[] = "hello";
  char cStrB[] = "hello";
  if (std::strcmp(cStrA, cStrB) == 0) {
    cout << "c 风格字符串内容 相等" << endl;
  } else {
    cout << "c 风格字符串内容 不相等" << endl;
  }

  return 0;
}

int p3_40 () {
  const char cStrA[] = "hello";
  const char cStrB[] = "world";

  size_t resLen = std::strlen(cStrA) + std::strlen(" ") + std::strlen(cStrB);
  char sStrRes[resLen];
  std::strcpy(sStrRes, cStrA);
  std::strcat(sStrRes, " ");
  std::strcat(sStrRes, cStrB);

  cout << sStrRes << endl;

  return 0;
}

// 练习3.41：编写一段程序，用整型数组初始化一个vector对象。
int p3_41 () {
  int intArr[] = {1, 2, 3, 4, 5};
  vector<int> vecArr;
  auto *start = std::begin(intArr);
  auto *end = std::end(intArr);
  while (start != end) {
    vecArr.push_back(*start);
    start++;
  }
  for (auto v : vecArr) {
    cout << v << endl;
  }
  return 0;
}

// 练习3.42：编写一段程序，将含有整数元素的 vector 对象拷贝给一个整型数组。
int p3_42 () {
  vector<int> vecArr = {5, 4, 3, 3, 2, 1};
  size_t len = vecArr.size();
  int intArr[len];

  for (size_t i = 0; i < vecArr.size(); i++) {
    intArr[i] = vecArr[i];
  }

  for (auto v : intArr) {
    cout << v << endl;
  }

  return 0;
}

/**
 * 练习3.43：编写3个不同版本的程序，令其均能输出ia的元素。
 * 版本1使用范围for语句管理迭代过程；
 * 版本2和版本3都使用普通的for语句，其中版本2要求用下标运算符，版本3要求用指针。
 * 此外，在所有3个版本的程序中都要直接写出数据类型，而不能使用类型别名、auto关键字或decltype关键字。
 */
int p3_43 () {
  int ia[3][4] = {
    { 0, 1, 2, 3 },
    { 4, 5, 6, 7 },
    { 8, 9, 10, 11 },
  };

  cout << "version 1:" << endl;
  for (int (&row)[4]: ia) {
    for (int el: row) {
      cout << el << ",";
    }
  }
  cout << endl;

  cout << "version 2:" << endl;
  for (size_t i = 0; i < std::size(ia); i++) {
    int (&row)[4] = ia[i];

    for (size_t j = 0; j < std::size(row); j++) {
      cout << row[j] << ",";
    }
  }
  cout << endl;

  cout << "version 3:" << endl;
  for (int (*rowBegin)[4] = std::begin(ia); rowBegin != std::end(ia); rowBegin++) {
    for (int *el = std::begin(*rowBegin); el != std::end(*rowBegin); el++) {
      cout << *el << ",";
    }
  }
  cout << endl;

  return 0;
}

/**
 * 练习3.44：改写上一个练习中的程序，使用类型别名来代替循环控制变量的类型。
 */
int p3_44 () {
  int ia[3][4] = {
    { 0, 1, 2, 3 },
    { 4, 5, 6, 7 },
    { 8, 9, 10, 11 },
  };

  typedef int TypeRow[4];
  typedef TypeRow &RefRow;
  typedef TypeRow *PointRow;
  // typedef int (&RefRow)[4];
  // typedef int (*PointRow)[4];

  cout << "version 1:" << endl;
  for (RefRow row: ia) {
    for (int el: row) {
      cout << el << ",";
    }
  }
  cout << endl;

  cout << "version 2:" << endl;
  for (size_t i = 0; i < std::size(ia); i++) {
    RefRow row = ia[i];

    for (size_t j = 0; j < std::size(row); j++) {
      cout << row[j] << ",";
    }
  }
  cout << endl;

  cout << "version 3:" << endl;
  for (PointRow rowBegin = std::begin(ia); rowBegin != std::end(ia); rowBegin++) {
    for (int *el = std::begin(*rowBegin); el != std::end(*rowBegin); el++) {
      cout << *el << ",";
    }
  }
  cout << endl;

  return 0;
}

/**
 * 练习3.45：再一次改写程序，这次使用auto关键字。
 */
int p3_45 () {
  int ia[3][4] = {
    { 0, 1, 2, 3 },
    { 4, 5, 6, 7 },
    { 8, 9, 10, 11 },
  };


  cout << "version 1:" << endl;
  for (auto &row: ia) {
    for (int el: row) {
      cout << el << ",";
    }
  }
  cout << endl;

  cout << "version 2:" << endl;
  for (size_t i = 0; i < std::size(ia); i++) {
    auto &row = ia[i];

    for (size_t j = 0; j < std::size(row); j++) {
      cout << row[j] << ",";
    }
  }
  cout << endl;

  cout << "version 3:" << endl;
  for (auto rowBegin = ia; rowBegin != ia + 3; rowBegin++) {
    for (auto el = *rowBegin; el != *rowBegin + 4; el++) {
      cout << *el << ",";
    }
  }
  cout << endl;

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
  p3_37();
  // p3_38();
  p3_39();
  p3_40();
  p3_41();
  p3_42();
  p3_43();
  p3_44();
  p3_45();

  return 0;
}
