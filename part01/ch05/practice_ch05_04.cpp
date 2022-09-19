#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::endl;
using std::getline;

/**
 * 练习5.14：编写一段程序，从标准输入中读取若干string对象并查找连续重复出现的单词。
 * 所谓连续重复出现的意思是：一个单词后面紧跟着这个单词本身。
 * 要求记录连续重复出现的最大次数以及对应的单词。
 * 如果这样的单词存在，输出重复出现的最大次数；
 * 如果不存在，输出一条信息说明任何单词都没有连续出现过。
 *
 * 例如，如果输入是how now now now brown cow cow 那么输出应该表明单词now连续出现了3次。
 */
int p5_14 () {
  vector<string> input = {"how", "now", "now", "now", "brown", "cow", "cow"};
  auto beg = input.begin();
  auto end = input.end();

  int temp = 1;
  int max = 0;
  while (beg != end) {
    if (*beg == *(beg + 1)) {
      ++temp;
    } else {
      max = std::max(max, temp);
      temp = 1;
    }
    ++beg;
  }

  cout << "最大连续出现次数为" << max << endl;

  return 0;
}

/**
 * 练习5.15：说明下列循环的含义并改正其中的错误。
 */
int p5_15 () {
  // a
  int sz = 10;
  // for头申明的必须在 for 块里面使用
  for (int ix = 0; ix != sz; ++ix) {
    if (ix != sz) {
      //...
    }
  }

  // b
  // 必须加个分号
  int ix2;
  for (; ix2 != sz; ++ix2) {
    /* code */
  }

  // c
  // ++sz 不能写，不然永远不能退出循环
  for (int ix3 = 0; ix3 != sz; ++ix3/**, ++sz*/) {
    /* code */
  }


  return 0;
}

int p5_16 () {
  // 根据实际情况选择 for 还是 while
  return 0;
}

/**
 * 练习5.17：假设有两个包含整数的vector对象，编写一段程序，检验其中一个vector对象是否是另一个的前缀。
 * 为了实现这一目标，对于两个不等长的vector对象，只需挑出长度较短的那个，把它的所有元素和另一个vector对象比较即可。
 * 例如，如果两个vector对象的元素分别是0、1、1、2和0、1、1、2、3、5、8，则程序的返回结果应该为真。
 */
bool p5_17 () {
  vector<int> vec1 = {0, 1, 1, 2};
  vector<int> vec2 = {0, 1, 1, 2, 3, 5, 9};

  int minLen = std::min(vec1.size(), vec2.size());

  for (int i = 0; i < minLen; ++i) {
    if (vec1[i] != vec2[2]) {
      cout << "不匹配" << endl;
      return false;
    }
  }
  cout << "匹配" << endl;
  return true;
}

int get_response () {
  return 1;
}

/**
 * 练习5.18：说明下列循环的含义并改正其中的错误。
 */
int p5_18 () {
  // a
  // do 需要添加花括号
  do {
    int v1, v2;
    cout << "Please enter two numbers to sum:";
    if (cin >> v1 >> v2) {
      cout << "Sum is" << v1 + v2 << endl;
    }
 } while (cin);

  // b
  // ival 要放在 do while 外面
  int ival;
  do {
  } while (ival = get_response());

  // c
  // ival 要放在 do while 外面
  int ival2;
  do {
    ival2 = get_response();
  } while (ival2);
  return 0;
}

/**
 * 练习5.19：编写一段程序，使用do while循环重复地执行下述任务：首先提示用户输入两个string对象，然后挑出较短的那个并输出它。
 */
int p5_19 () {
  do
  {
    cout << "请输入两个字符串" << endl;
    string s1, s2;
    if (cin >> s1 >> s2) {
      cout << "较短字符串为";
      cout << (s1.size() < s2.size() ? s1 : s2) << endl; // 没有考虑相等
    }
  } while (cin);

  return 0;
}

int main () {
  p5_14();
  p5_15();
  p5_16();
  p5_17();
  p5_18();
  p5_19();

  return 0;
}
