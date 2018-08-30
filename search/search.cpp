#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cstdlib>

#include "search.h"

using namespace std;

string search(string query, vector<string> fileNames)
{
  string line;
  ifstream file;

  for(vector<string>::reverse_iterator it = fileNames.rbegin(); it != fileNames.rend(); ++it)
  {
    string fileName = *it;
    file.open("../files/" + fileName);
    if(file.is_open()){
      bool returnNextLine = false;
      while(!file.eof())
      {
        getline(file, line);
        if(returnNextLine){
          returnNextLine = false;
          return line;
        }
        if(line.find(query) != string::npos) returnNextLine = true;
      }
      file.close();
    } else {
        cout << "Can't open file" << endl;
    }
  }
}
