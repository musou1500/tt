#ifndef INCHWORM_HH
#define INCHWORM_HH

#include <vector>

namespace tt {

long long Inchworm(std::vector<long long> &va, long long k) {
  long long left, right, sum, ans;
  left = right = sum = ans = 0;
  while (left < va.size()) {
    while (right < va.size() && sum + va[right] < k) {
      sum += va[right];
      right++;
    }

    long long cnt = va.size() - right;
    ans += cnt;

    sum -= va[left];
    if (left == right) {
      right++;
      sum = 0;
    }
    left++;
  }

  return ans;
}

}  // namespace tt

#endif
