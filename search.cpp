#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "search.h"

using namespace std;

void search()
{
  string contentsFileName = "contents.txt";
  string searchStr;
  string line;
  ifstream file;
  vector <string> fileNames;

  // Contents txt
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

  cout << "Search: \n" << endl;
  getline(cin, searchStr);

  // files
  for(std::vector<string>::reverse_iterator it = fileNames.rbegin(); it != fileNames.rend(); ++it)
  {
    string fileName = *it;

    file.open("./files/" + fileName);
    if(file.is_open()){
      while(!file.eof())
      {
        getline(file, line);

        if(line.find(searchStr) != string::npos)
        {
          system(("cd files & " + fileName  ).c_str());
        }
      }
      file.close();
    } else {
        cout << "Can't open file" << endl;
    }
  }
}

// void toClipboard(const std::string &s){
//   OpenClipboard(0);
//   EmptyClipboard();
//   HGLOBAL hg=GlobalAlloc(GMEM_MOVEABLE,s.size());
//   if (!hg){
//   CloseClipboard();
//   return;
//   }
//   memcpy(GlobalLock(hg),s.c_str(),s.size());
//   GlobalUnlock(hg);
//   SetClipboardData(CF_TEXT,hg);
//   CloseClipboard();
//   GlobalFree(hg);
// }
