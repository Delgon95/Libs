#ifndef TIMER_H_
#define TIMER_H_

#include <chrono>
#include <string>

namespace delgon {

class Timer {
 public:
  Timer();
  // All functions return elapsed time calculated with
  // end time being function execution.

  // Returns elapsed time in given format.
  double Seconds();
  double Minutes();
  double Hours();

  // Returns elapsed time in format XXh YYm ZZs KKms.
  // Returns only meningfull values - for 5m 24s it will not return 'h' value.
  std::string Formatted();
 private:
  std::chrono::steady_clock::time_point start_;
};

} // namespace delgon
#endif // TIMER_H_
