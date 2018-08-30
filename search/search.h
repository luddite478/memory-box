#ifndef SEARCH_H
#define SEARCH_H

#include <string>
#include <vector>

using namespace std;

extern "C" {
  string search(string query, vector<string> fileNames);
}

#endif
