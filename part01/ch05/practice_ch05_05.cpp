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
 * 练习5.20：编写一段程序，从标准输入中读取string对象的序列直到连续出现两个相同的单词或者所有单词都读完为止。
 * 使用while循环一次读取一个单词，当一个单词连续出现两次时使用break语句终止循环。
 * 输出连续重复出现的单词，或者输出一个消息说明没有任何单词是连续重复出现的。
 */
int p5_20 () {
  string prev;
  string cur;

  while (cin >> cur) {
    if (prev == cur) {
      cout << "单词" << cur << "重复" << endl;
      break;
    }
    prev = cur;
  }

  return 0;
}

/**
 * 练习5.21：修改5.5.1节（第171页）练习题的程序，使其找到的重复单词必须以大写字母开头。
 */
int p5_21 () {
  string prev;
  string cur;

  while (cin >> cur) {
    if (std::islower(cur[0])) {
      cout << "首字母必须大写，输入无效，重新输入" << endl;
      continue;
    }
    if (prev == cur) {
      cout << "单词" << cur << "重复" << endl;
      break;
    }
    prev = cur;
  }

  return 0;
}

int get_size () {
  return 1;
}

/**
 * 练习5.22：本节的最后一个例子跳回到begin，其实使用循环能更好地完成该任务。重写这段代码，注意不再使用goto语句。
 */
int p5_22 () {
  // begin:
  //   int sz = get_size();
  //   if (sz <= 0) {
  //     goto begin;
  //   }

  int sz;
  do {
    sz = get_size();
  } while (sz <= 0);

  return 0;
}

int main () {
  p5_20();
  p5_21();
  p5_22();

  return 0;
}
