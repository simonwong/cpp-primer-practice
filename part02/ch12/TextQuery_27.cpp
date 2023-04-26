#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <map>
#include <set>
#include <stdexcept>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;
using std::getline;

class QueryResult_27 {
friend std::ostream& print_27(std::ostream&, const QueryResult_27&);
public:
  using line_no = vector<string>::size_type;

  QueryResult_27(string s,
    std::shared_ptr<std::set<line_no>> p,
    std::shared_ptr<vector<string>> f): sought(s), lines(p), file(f) {}
private:
  string sought;
  std::shared_ptr<std::set<line_no>> lines;
  std::shared_ptr<vector<string>> file;
};

class TextQuery_27 {
friend class QueryResult_27;
public:
  using line_no = vector<string>::size_type;

  TextQuery_27(std::ifstream &ifs): file(new vector<string>) {
    string text;

    while (getline(ifs, text)) {
      file->push_back(text);
      int n = file->size() - 1;

      std::istringstream line(text);
      string word;
      while (line >> word) {
        auto &lines = wm[word];

        if (!lines) {
          lines.reset(new std::set<line_no>);
        }
        lines->insert(n);
      }
    }
  }

  QueryResult_27 query(string const& s) const {
    static std::shared_ptr<std::set<line_no>> noData(new std::set<line_no>);

    auto lineSet = wm.find(s);

    if (lineSet ==  wm.end()) {
      return QueryResult_27(s, noData, file);
    } else {
      return QueryResult_27(s, lineSet->second, file);
    }
  }

private:
  std::shared_ptr<vector<string>> file;
  std::map<string, std::shared_ptr<std::set<line_no>>> wm;
};

string make_plural(size_t ctr, const string& word, const string& ending) {
  return (ctr > 1) ? word + ending : word;
}

std::ostream& print_27(std::ostream &os, const QueryResult_27 &qr) {
  os << qr.sought << " occurs " << qr.lines->size() << " "
    << make_plural(qr.lines->size(), "time", "s") << endl;

  for (auto num : *qr.lines) {
    os << "\t(line " << num + 1 << ") "
      << *(qr.file->begin() + num) << endl;
  }

  return os;
}
