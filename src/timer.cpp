#include <cmath>

#include "timer.h"

namespace delgon {

Timer::Timer()
    : start_(std::chrono::steady_clock::now()) {
}

double Timer::Seconds() {
  return std::chrono::duration<double>(std::chrono::steady_clock::now() -
                                       start_).count();
}

double Timer::Minutes() {
  return std::chrono::duration<double>(std::chrono::steady_clock::now() -
                                      start_).count() / 60.0;
}

double Timer::Hours() {
  return std::chrono::duration<double>(std::chrono::steady_clock::now() -
                                       start_).count() / 3600.0;
}

std::string Timer::Formatted() {
  auto end = std::chrono::steady_clock::now();
  auto elapsed = std::chrono::duration<double>(end - start_);
  double ms = elapsed.count() * 1000.0;
  double s = elapsed.count();
  double m = elapsed.count() / 60.0;
  double h = elapsed.count() / 3600.0;

  // Format result.
  char* res = new char;
  if (h >= 1.0) {
    std::sprintf(res, "%.2dh %.2dm %.2ds %.3lfms", static_cast<int>(h),
                                                   static_cast<int>(std::fmod(m, 60.0)),
                                                   static_cast<int>(std::fmod(s, 60.0)),
                                                   std::fmod(ms, 1000.0));
  } else if (m >= 1.0) {
    std::sprintf(res, "%.2dm %.2ds %.3lfms", static_cast<int>(m),
                                             static_cast<int>(std::fmod(s, 60.0)),
                                             std::fmod(ms, 1000.0));
  } else if (s >= 1.0) {
    std::sprintf(res, "%.2ds %.3lfms", static_cast<int>(s),
                                       std::fmod(ms, 1000.0));
  } else {
    std::sprintf(res, "%.3lf ms", ms);
  }

  return std::string(res);
}

} // namespace delgon
