#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cstdlib>

#include "search.h"

using namespace std;

std::string search(std::string query)
{
  string contentsFileName = "../contents.txt";
  string line;
  ifstream file;
  vector <string> fileNames;

  // read contents.txt
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
  } else {
      cout << "Can't open contents file" << endl;
  }

  // search in each file from contents.txt
  for(std::vector<string>::reverse_iterator it = fileNames.rbegin(); it != fileNames.rend(); ++it)
  {
    string fileName = *it;
    file.open("../files/" + fileName);
    if(file.is_open()){
      bool returnNextLine = false;
      //lines iterations
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
