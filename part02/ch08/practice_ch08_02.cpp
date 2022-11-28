#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::endl;
using std::istream;

/**
 * 练习8.4：编写函数，以读模式打开一个文件，将其内容读入到一个string的vector中，将每一行作为一个独立的元素存于vector中。
 */
void getStringVecByReadFile (const string& path) {
  vector<string> res;
  std::ifstream inputFile(path);

  if (inputFile) {
    string cur;
    while (std::getline(inputFile, cur)) {
      res.push_back(cur);
    }
  }

  for (const auto& rowText : res) {
    cout << rowText << endl;
  }
}
void p8_4 () {
  getStringVecByReadFile("./practice_ch08_01.cpp");
}

int main () {
  p8_4();

  return 0;
}
