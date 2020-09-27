#include "../segment_tree.hh"
#include <cmath>
#include <functional>
#include <iostream>

int main(int argc, char *argv[]) {
  const int inf = 2 * std::pow(10, 5), n = 100;
  tt::SegmentTree<int, std::plus<int>> range_sum(n, 0);
  tt::SegmentTree<int> range_min(n, inf,
                                 [](auto a, auto b) { return std::min(a, b); });
  tt::SegmentTree<int> range_max(n, 0,
                                 [](auto a, auto b) { return std::max(a, b); });
  return 0;
}
