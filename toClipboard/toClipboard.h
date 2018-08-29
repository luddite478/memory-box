#ifndef TO_CLIPBOARD
#define TO_CLIPBOARD

#include <string>

extern "C" {
  void toClipboard(const std::string &s);
}

#endif
