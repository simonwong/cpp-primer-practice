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

/**
 * 练习10.14：编写一个lambda，接受两个int，返回它们的和。
 */
void p10_14 () {
  auto add = [](int a, int b) {
    return a + b;
  };
  cout << add(5, 3) << endl;
}

/**
 * 练习10.15：编写一个lambda，捕获它所在函数的int，并接受一个int参数。lambda应该返回捕获的int和int参数的和。
 */
void p10_15 () {
  int it = 12;
  auto add = [it](int a) {
    return a + it;
  };
  cout << add(10) << endl;
}

/**
 * 练习10.16：使用lambda编写你自己版本的biggies。
 */
string make_plural(long iter, const string &str, const string &suffix) {
  return "sad";
}
void biggies (vector<string> &words, vector<string>::size_type sz) {
  elimDups(words);

  std::stable_sort(words.begin(), words.end(), [](const string &a, const string &b) {
    return a.size() < b.size();
  });
  auto wc = std::find_if(words.begin(), words.end(), [sz](const string &a) {
    return a.size() >= sz;
  });

  auto count = words.end() - wc;

  cout << count << " " << make_plural(count, "word", "s") << " of length " << sz << " or longer " << endl;

  std::for_each(wc, words.end(), [](const string &s) {
    cout << s << " ";
  });
  cout << endl;
}
void p10_16 () {
  vector<string> words = {"asd", "zxcv", "dfgreq", "a", "a", "sfsd", "fg", "dfgreq", "w44wa"};

  biggies(words, 3);
}

int main () {
  p10_11();
  p10_12();
  p10_13();
  p10_14();
  p10_15();
  p10_16();

  return 0;
}
