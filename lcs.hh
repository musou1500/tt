#ifndef LCS_HH
#define LCS_HH

#include <algorithm>
#include <string>
#include <vector>

namespace tt {

int LcsLen(std::string &s, std::string &t, std::vector<std::vector<int>> &memo,
           int i, int j) {
  if (i < 0 || j < 0) {
    return 0;
  }

  if (memo[i][j] < 0) {
    if (s[i] == t[j]) {
      memo[i][j] = LcsLen(s, t, memo, i - 1, j - 1) + 1;
    } else {
      memo[i][j] =
          std::max(LcsLen(s, t, memo, i - 1, j), LcsLen(s, t, memo, i, j - 1));
    }
  }

  return memo[i][j];
}

std::string Lcs(std::string &s, std::string &t,
                std::vector<std::vector<int>> &memo, int i, int j) {
  if (i < 0 || j < 0) {
    return "";
  }

  if (s[i] == t[j]) {
    return Lcs(s, t, memo, i - 1, j - 1) + s[i];
  }

  if (LcsLen(s, t, memo, i, j - 1) < LcsLen(s, t, memo, i - 1, j)) {
    return Lcs(s, t, memo, i - 1, j);
  } else {
    return Lcs(s, t, memo, i, j - 1);
  }
}

}  // namespace tt

#endif
