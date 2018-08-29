#include <iostream>
#include <string>

#include "search/search.h"
#include "toClipboard/toClipboard.h"

using namespace std;

int main() {
  string query;
  string result;

  cout << "\nSearch: \n" << endl;
  getline(cin, query);
  result = search(query);
  toClipboard(result);
  // system(("cd files & " + fileName  ).c_str());
  return 0;
}
