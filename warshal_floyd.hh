#ifndef WARSHAL_FLOYD_HH
#define WARSHAL_FLOYD_HH

#include <algorithm>
#include <vector>

namespace tt {

void WarshalFloyd(std::vector<std::vector<int>>& dists) {
  int n = dists.size();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
        dists[j][k] = std::min(dists[j][k], dists[j][i] + dists[i][k]);
      }
    }
  }
}
}  // namespace tt

#endif
