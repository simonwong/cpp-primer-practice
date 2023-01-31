#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <string>
#include <numeric>
#include <iterator>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::list;
using std::string;

/**
 * 练习10.11：编写程序，使用stable_sort和isShorter将传递给你的elimDups版本的vector排序。
 * 打印vector的内容，验证你的程序的正确性。
 */
void printVectorList (const vector<string>& vec, const string& title) {
  cout << title << ": ";
  for (auto i : vec) {
    cout << i << ",";
  }
  cout << endl;
}
bool isShorter(const string& s1, const string& s2) {
  return s1.size() < s2.size();
}
void elimDups (vector<string>& vec) {
  printVectorList(vec, "Origin");

  std::sort(vec.begin(), vec.end());

  printVectorList(vec, "Sort");

  auto end_unique = std::unique(vec.begin(), vec.end());

  printVectorList(vec, "Unique");

  vec.erase(end_unique, vec.end());

  printVectorList(vec, "Erase");

  std::stable_sort(vec.begin(), vec.end(), isShorter);

  printVectorList(vec, "stable_sort");
}

void p10_11 () {
  vector<string> strVec = {"asda", "asdxc", "vbn", "a", "c", "vbn", "tytr", "cx", "hjhg"};
  elimDups(strVec);
}

/**
 * 练习10.12：编写名为compareIsbn的函数，比较两个Sales_data对象的isbn（）成员。使用这个函数排序一个保存Sales_data对象的vector。
 */
class Sales_data {
public:
  Sales_data(const string &s): bookNo(s) {};
  std::string isbn() const { return bookNo; };
private:
  string bookNo;
};
bool compareBn(const Sales_data& s1, const Sales_data& s2) {
  return s1.isbn() < s2.isbn();
}
void compareIsbn (vector<Sales_data>& vec) {
  std::stable_sort(vec.begin(), vec.end(), compareBn);
}
void p10_12 () {

  Sales_data s1("6574");
  Sales_data s2("4002");
  Sales_data s3("4253");
  Sales_data s4("2012");
  Sales_data s5("0001");
  Sales_data s6("2003");

  vector<Sales_data> salesDataVec{s1, s2, s3, s4, s5, s6};

  compareIsbn(salesDataVec);

  for (auto i : salesDataVec) {
    cout << i.isbn() << ",";
  }
  cout << endl;
}

/**
 * 练习10.13：标准库定义了名为partition的算法，
 * 它接受一个谓词，对容器内容进行划分，使得谓词为true的值会排在容器的前半部分，而使谓词为false的值会排在后半部分。
 * 算法返回一个迭代器，指向最后一个使谓词为true的元素之后的位置。
 * 编写函数，接受一个string，返回一个bool值，指出string是否有5个或更多字符。
 * 使用此函数划分words。打印出长度大于等于5的元素。
 */
bool partitionStringCompare (const string& s1) {
  return s1.size() < 5;
}
void p10_13 () {
  vector<string> strVec = {"hello", "welcome", "California", "sometimes", "fine", "just", "ok", "never", "nothing"};

  auto partIter = std::partition(strVec.begin(), strVec.end(), partitionStringCompare);

  while (partIter != strVec.end()) {
    cout << *partIter << ",";
    ++partIter;
  }
  cout << endl;
}

int main () {
  p10_11();
  p10_12();
  p10_13();

  return 0;
}
