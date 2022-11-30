#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Sales_data.h"

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

/**
 * 练习8.5：重写上面的程序，将每个单词作为一个独立的元素进行存储。
 */
void getWordVecByReadFile (const string& path) {
  vector<string> res;
  std::ifstream inputFile(path);

  if (inputFile) {
    string cur;
    while (inputFile >> cur) {
      res.push_back(cur);
    }
  }

  for (const auto& rowText : res) {
    cout << rowText << endl;
  }
}
void p8_5 () {
  getWordVecByReadFile("./practice_ch08_01.cpp");
}

void p8_06_07_08 (const string& fromPath, const string& savePath) {
  std::ifstream inputFile(fromPath);
  std::ofstream outputFile;

  Sales_data total;

  outputFile.open(savePath, std::ofstream::app);
  if (read(inputFile, total)) {
    Sales_data trans;

    while (read(inputFile, trans)) {
      if (total.isbn() == trans.isbn()) {
        total.combine(trans);
      } else {
        print(outputFile, total) << endl;

        total = trans;
      }
    }
    print(outputFile, total) << endl;
  } else {
    cout << "No Data" << endl;
  }
  outputFile.close();
}

int main (int argc, char **argv) {
  p8_4();
  p8_5();
  p8_06_07_08("sales_data.txt", "sales_data_res.txt");

  return 0;
}
