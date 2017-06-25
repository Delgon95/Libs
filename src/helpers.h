#ifndef HELPERS_H_
#define HELPERS_H_

#include <cmath>
#include <string>
#include <vector>

namespace delgon {

// Check if value is zero. Used for floating point variables.
template <class T>
bool IsZero(T value, T eps = 1e-18) {
  return std::fabs(value) < eps;
}

// Returns string with removed whitespaces from beginning and end of string.
std::string Trim(const std::string& str);

// Returns split string by delimiter.
std::vector<std::string> Split(const std::string& str,
                               const std::string& delimiter);

// Returns split string by whitespaces " \t\n"
std::vector<std::string> SplitWhitespaces(const std::string& str);

} // namesapce delgon
#endif // HELPERS_H_
