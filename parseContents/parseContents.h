#ifndef PARSE_CONTENTS
#define PARSE_CONTENTS

#include <string>
#include <vector>

using namespace std;

extern "C" {
  vector<string> parseContents(string contentsFileName);
}

#endif
