#ifndef SEGMENT_TREE_HH
#define SEGMENT_TREE_HH

#include <algorithm>
#include <functional>
#include <vector>

namespace tt {

template <typename T, typename Op = std::function<T(const T &, const T &)>>
class SegmentTree {
 private:
  std::vector<T> data_;
  int size_;
  Op op_;
  T id_;

  T QuerySub(int left, int right, int k, int k_left, int k_right) {
    if (right <= k_left || k_right <= left) {
      return id_;
    } else if (left <= k_left && k_right <= right) {
      return data_[k];
    } else {
      int mid = (k_left + k_right) / 2;
      return op_(QuerySub(left, right, k * 2 + 1, k_left, mid),
                 QuerySub(left, right, k * 2 + 2, mid, k_right));
    }
  }

 public:
  T operator[](int pos) { return data_[pos + size_ - 1]; }

  SegmentTree(int size, T id, const Op &op = Op()) : op_(op), id_(id) {
    size_ = 1;
    while (size_ < size) {
      size_ *= 2;
    }

    data_.resize(size_ * 2 - 1);
    std::fill(data_.begin(), data_.end(), id_);
  };

  void Update(int pos, T val) {
    pos += size_ - 1;
    data_[pos] = val;
    while (pos > 0) {
      pos = (pos - 1) / 2;
      data_[pos] = op_(data_[pos * 2 + 1], data_[pos * 2 + 2]);
    }
  }

  T Query(int left, int right) { return QuerySub(left, right, 0, 0, size_); }
  T QueryAll() { return QuerySub(0, size_, 0, 0, size_); }
};

}  // namespace tt

#endif
