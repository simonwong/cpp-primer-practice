#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::endl;
using std::getline;

int main (int argc, char **argv) {
  string res;

  for (int i = 1; i < argc; i++) {
    res += string(argv[i]) + " ";
  }
  cout << res << endl;
  return 0;
}
