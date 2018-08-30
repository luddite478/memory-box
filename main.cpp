#include <iostream>
#include <string>
#include <vector>

#include "parseContents/parseContents.h"
#include "search/search.h"
#include "toClipboard/toClipboard.h"

using namespace std;

int main() {
  string query;
  string result;
  vector<string> fileNames;

  fileNames = parseContents("../contents.txt");
  cout << "\nSearch: \n" << endl;
  getline(cin, query);
  result = search(query, fileNames);
  toClipboard(result);
  // system(("cd files & " + fileName  ).c_str());
  return 0;
}
