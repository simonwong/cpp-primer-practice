#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::istream;

/**
 * 练习8.1：编写函数，接受一个istream&参数，返回值类型也是istream&。
 * 此函数须从给定流中读取数据，直至遇到文件结束标识时停止。
 * 它将读取的数据打印在标准输出上。完成这些操作后，在返回流之前，对流进行复位，使其处于有效状态。
 *
 * 练习8.2：测试函数，调用参数为cin。
 */
istream& getInStream (istream& in) {
  string str;
  while (in >> str) {
    cout << str << endl;
  }
  cin.clear();

  return in;
}
void p8_1_2 () {
  istream& is = getInStream(cin);
  cout << "is rdstate: " << is.rdstate() << endl;
}

/**
 * 练习8.3：什么情况下，下面的while循环会终止？
 */
void p8_3 () {
  string i;
  while (cin >> i) {
  }

  // 当状态变为 eofbit、 failbit、 badbit 会终止
}

int main () {
  p8_1_2();
  p8_3();

  return 0;
}
