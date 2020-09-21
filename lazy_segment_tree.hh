#ifndef LAZY_SEGMENT_TREE_HH
#define LAZY_SEGMENT_TREE_HH

#include <vector>

namespace tt
{
template <typename T>
class LazySegmentTree {
  std::vector<T> data_;
  std::vector<T> lazy_;
  int size_;

  void Eval(int k) {
    if (lazy_[k] == 0) {
      return;
    }

    if (k < size_ - 1) {
      lazy_[k * 2 + 1] += lazy_[k];
      lazy_[k * 2 + 2] += lazy_[k];
    }

    data_[k] += lazy_[k];
    lazy_[k] = 0;
  }

  void UpdateSub(int a, int b, T x, int k, int l, int r) {
    Eval(k);
    if (a <= l && r <= b) {
      lazy_[k] += x;
      Eval(k);
    } else if (a < r && l < b) {
      UpdateSub(a, b, x, k * 2 + 1, l, (l + r) / 2);
      UpdateSub(a, b, x, k * 2 + 2, (l + r) / 2, r);
      data_[k] = data_[k * 2 + 1] + data_[k * 2 + 2];
    }
  }

  T QuerySub(int a, int b, int k, int l, int r) {
    Eval(k);
    if (r <= a || b <= l) {
      return 0;
    } else if (a <= l && r <= b) {
      return data_[k];
    } else {
      return QuerySub(a, b, k * 2 + 1, l, (l + r) / 2) +
             QuerySub(a, b, k * 2 + 2, (l + r) / 2, r);
    }
  }

 public:
  LazySegmentTree(int size) : data_(), lazy_() {
    int n = 1;
    while (size > n) {
      n *= 2;
    }

    size_ = n;
    data_.resize(n * 2 - 1);
    lazy_.resize(n * 2 - 1);
    fill(data_.begin(), data_.end(), 0);
    fill(lazy_.begin(), lazy_.end(), 0);
  }

  void Update(int a, int b, T x) { UpdateSub(a, b, x, 0, 0, size_); }
  T Query(int a, int b) { return QuerySub(a, b, 0, 0, size_); }
  T Query(int a) { return Query(a, a + 1); }
};

} /* tt */ 

#endif
