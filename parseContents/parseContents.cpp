#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cstdlib>

#include "parseContents.h"

using namespace std;

vector<string> parseContents(string contentsFileName)
{
  string line;
  ifstream file;
  vector<string> fileNames;

  file.open(contentsFileName);
  if(file.is_open())
  {
    while(!file.eof())
    {
      getline(file, line);
      if (line == "") continue;
      fileNames.push_back(line);
    }
    file.close();
    return fileNames;
  } else {
      cout << "Can't open contents file" << endl;
  }
}
