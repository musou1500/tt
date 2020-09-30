#ifndef LAZY_SEGMENT_TREE_HH
#define LAZY_SEGMENT_TREE_HH

#include <algorithm>
#include <functional>
#include <vector>

namespace tt {
template <typename T, typename U>
class LazySegmentTree {
 public:
  using Op = std::function<T(T, T)>;
  using Comp = std::function<U(U, U)>;
  using Mapping = std::function<T(T, U)>;

 private:
  std::vector<T> data_;
  std::vector<U> lazy_;
  T e_;
  Op op_;
  U id_;
  Mapping mapping_;
  Comp comp_;
  int size_;

  void Eval(int k) {
    if (k < size_ - 1) {
      lazy_[k * 2 + 1] = comp_(lazy_[k * 2 + 1], lazy_[k]);
      lazy_[k * 2 + 2] = comp_(lazy_[k * 2 + 2], lazy_[k]);
    }

    data_[k] = mapping_(data_[k], lazy_[k]);
    lazy_[k] = id_;
  }

  void UpdateSub(int a, int b, U x, int k, int l, int r) {
    Eval(k);
    if (a <= l && r <= b) {
      lazy_[k] = comp_(lazy_[k], x);
      Eval(k);
    } else if (r > a && b > l) {
      UpdateSub(a, b, x, k * 2 + 1, l, (l + r) / 2);
      UpdateSub(a, b, x, k * 2 + 2, (l + r) / 2, r);
      data_[k] = op_(data_[k * 2 + 1], data_[k * 2 + 2]);
    }
  }

  T QuerySub(int a, int b, int k, int l, int r) {
    Eval(k);
    if (r <= a || b <= l) {
      return e_;
    } else if (a <= l && r <= b) {
      return data_[k];
    } else {
      return op_(QuerySub(a, b, k * 2 + 1, l, (l + r) / 2),
                 QuerySub(a, b, k * 2 + 2, (l + r) / 2, r));
    }
  }

 public:
  LazySegmentTree(const std::vector<T> &v, T e, const Op &op, U id,
                  const Mapping &mapping, const Comp &comp)
      : data_(),
        lazy_(),
        e_(e),
        op_(op),
        id_(id),
        mapping_(mapping),
        comp_(comp) {
    int n = 1;
    while (v.size() > n) {
      n *= 2;
    }

    size_ = n;
    data_.resize(n * 2 - 1);
    std::copy(v.begin(), v.end(), data_.begin() + (size_ - 1));
    for (int i = size_ - 2; i >= 0; --i) {
      data_[i] = op_(data_[i * 2 + 1], data_[i * 2 + 2]);
    }

    lazy_.resize(n * 2 - 1);
    fill(lazy_.begin(), lazy_.end(), id_);
  }

  LazySegmentTree(int n, T e, const Op &op, U id, const Mapping &mapping,
                  const Comp &comp)
      : LazySegmentTree(std::vector<T>(n, e), op, id, mapping, comp) {}

  void Update(int a, int b, U x) { UpdateSub(a, b, x, 0, 0, size_); }
  T Query(int a, int b) { return QuerySub(a, b, 0, 0, size_); }
  T Query(int a) { return Query(a, a + 1); }
  T QueryAll() { return Query(0, size_); }
  int Size() { return size_; }
};

}  // namespace tt

#endif
