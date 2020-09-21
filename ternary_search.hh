#ifndef TERNARY_SEARCH_HH
#define TERNARY_SEARCH_HH

#include <functional>

namespace tt {

double ternary_search(double lower, double upper,
                      std::function<double(double)> &predicate) {
  double l = lower, r = upper;
  for (int i = 0; i < 80; ++i) {
    double c1, c2;
    c1 = (l * 2 + r) / 3;
    c2 = (l + r * 2) / 3;
    if (predicate(c1) > predicate(c2)) {
      l = c1;
    } else {
      r = c2;
    }
  }

  return r;
}
}  // namespace tt

#endif
