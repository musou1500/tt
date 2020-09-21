#ifndef FENWICK_TREE_HH
#define FENWICK_TREE_HH

#include <vector>

namespace tt {
template <typename T>
class FenwickTree {
  std::vector<T> tree_;

 public:
  FenwickTree(int n) : tree_(n, 0) {}

  void Add(int i, T x) {
    for (i++; i <= tree_.size(); i += i & -i) {
      tree_[i - 1] += x;
    }
  }

  T Sum(int s) {
    T ans = 0;
    for (s++; s > 0; s -= s & -s) {
      ans += tree_[s - 1];
    }

    return ans;
  }

  // [l, r]
  T Sum(int l, int r) { return Sum(r) - Sum(l - 1); }
};
}  // namespace tt

#endif
