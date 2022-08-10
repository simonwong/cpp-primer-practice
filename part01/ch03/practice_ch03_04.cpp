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

int main () {
  p3_21_22();
  p3_23();
  p3_24();
  p3_25();
  p3_26();

  return 0;
}
