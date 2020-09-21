#ifndef BINARY_SEARCH_HH
#define BINARY_SEARCH_HH

#include <functional>
namespace tt {
int binary_search(long long left, long long right,
                  std::function<bool(long long)> &pred) {
  while (right - left > 1) {
    long long mid = (left + right) / 2;
    if (pred(mid)) {
      right = mid;
    } else {
      left = mid;
    }
  }

  return right;
}
}  // namespace tt

#endif
