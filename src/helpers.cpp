#include "helpers.h"

namespace delgon {

std::string Trim(const std::string& str) {
  auto wsfront = std::find_if_not(str.begin(), str.end(),
                                  [](int c){ return std::isspace(c); });
  auto wsback = std::find_if_not(str.rbegin(), str.rend(),
                                  [](int c){ return std::isspace(c); }).base();
  return (wsback <= wsfront ? "" : std::string(wsfront, wsback));
}

std::vector<std::string> Split(const std::string& str,
                               const std::string& delimiter) {
  std::vector<std::string> res;
  size_t pos = 0;
  size_t newpos;
  while ((newpos = str.find(delimiter, pos)) != std::string::npos) {
    res.push_back(str.substr(pos, newpos - pos));
    pos = newpos + delimiter.size();
  }
  // Add last element.
  res.push_back(str.substr(pos, newpos - pos));
  return res;
}

std::vector<std::string> SplitWhitespaces(const std::string& str) {
  std::vector<std::string> res;
  std::string::const_iterator pos = str.begin();
  std::string::const_iterator newpos;
  while ((newpos = std::find_if(pos, str.end(),
                                [](int c){ return std::isspace(c); }))
          != str.end()) {
    auto&& part = Trim(std::string(pos, newpos));
    if (part != "")
      res.push_back(part);
    pos = newpos + 1;
  }
  // Add last element.
  auto&& part = Trim(std::string(pos, newpos));
  if (part != "")
    res.push_back(part);
  return res;
}

}
