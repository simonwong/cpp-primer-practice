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
 * 练习5.5：写一段自己的程序，使用if else语句实现把数字成绩转换成字母成绩的要求。
 * 练习5.6：改写上一题的程序，使用条件运算符（参见4.7节，第134页）代替if else语句。
 */
int p5_05_06 () {
  int intScore = 88;
  string strScore;
  if (intScore < 60) {
    strScore = "C";
  } else if (intScore < 80) {
    strScore = "B";
  } else if (intScore < 95) {
    strScore = "A";
  } else {
    strScore = "S";
  }

  // 条件运算符
  // 略（写着太累了）
  return 0;
}

int get_value () {
  return 123;
}

/**
 * 练习5.7：改正下列代码段中的错误。
 */
int p5_07 () {
  // a（需要注意分号）
  int ival1 = 1;
  int ival2 = 1;
  if (ival1 != ival2)
    ival1 = ival2;
  else
    ival1 = ival2 = 0;
  // b（需要注意多行加花括号）
  int ival = 5;
  int minVal = 4;
  int occurs;
  if (ival < minVal) {
    minVal = ival;
    occurs = 1;
  }
  // c （if else）
  if (int ival = get_value())
    cout << "ival = " << ival << endl;
  else
    cout << "ival = 0\n";
  // d（注意条件判断）
  if (ival == 0)
    ival = get_value();
  return 0;
}

/**
 * 练习5.8：什么是“悬垂else”？C++语言是如何处理else子句的？
 */
int p5_08 () {
  if (1) {
    if (2) {
      if (3) {

      }
    }
  } else {

  }
  // else 与 离它最近的尚未匹配的if匹配
  return 0;
}

/**
 * 练习5.9：编写一段程序，使用一系列 if 语句统计从 cin 读入的文本中有多少元音字母。
 *
 * 练习5.10：我们之前实现的统计元音字母的程序存在一个问题：
 * 如果元音字母以大写形式出现，不会被统计在内。编写一段程序，既统计元音字母的小写形式，也统计大写形式，
 * 也就是说，新程序遇到'a'和'A'都应该递增aCnt的值，以此类推。
 *
 * 练习5.11：修改统计元音字母的程序，使其也能统计空格、制表符和换行符的数量。
 *
 * 练习5.12：修改统计元音字母的程序，使其能统计以下含有两个字符的字符序列的数量：ff、fl和fi。
 */
int p5_09_10_11_12  () {
  string str = "abcdefg";
  int count = 0;

  for (size_t i = 0; i < str.size(); i++) {
    char c = str[i];

    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
      ++count;
    } else if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
      ++count;
    } else if (std::isspace(c)) {
      ++count;
    } else if (i < str.size() - 1) {
      string ad;
      ad.push_back(c);
      ad.push_back(str[i+1]);
      if (ad == "ff" || ad == "fl" || ad == "fi") {
        ++count;
      }
    }
  }

  cout << "总共有" << count << "个元音" << endl;
  return 0;
}

/**
 * 练习5.13：下面显示的每个程序都含有一个常见的编程错误，指出错误在哪里，然后修改它们。
 */
int p5_13  () {
  // a
  // 没有 break

  // b
  // 没有必要 switch case，直接用 if 即可

  // c
  // 每个 case 都要写

  // d
  // 没有必要 switch case，直接用  swt 乘就行，除非要处理边界
  return 0;
}

int main () {
  p5_05_06();
  p5_07();
  p5_08();
  p5_09_10_11_12();
  p5_13();

  return 0;
}
