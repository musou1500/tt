#include "../lazy_segment_tree.hh"
#include <bits/stdc++.h>
#include <vector>

using namespace std;
using namespace tt;

int main(int argc, char *argv[]) {
  int n, q;
  cin >> n;

  // (値，区間の長さ)
  using El = pair<int, int>;

  vector<El> va(n, {0, 1});
  for (int i = 0; i < n; ++i) {
    cin >> va[i].first;
  }

  LazySegmentTree<El, int> seg_tree(
      va, {0, 1},
      [](El a, El b) -> El {
        return {a.first + b.first, a.second + b.second};
      },
      0,
      [](El a, int b) -> El {
        return {a.first + b * a.second, a.second};
      },
      [](int a, int b) { return a + b; });

  cout << seg_tree.Size() << '\n';
  auto [sum, len] = seg_tree.QueryAll();
  cout << sum << ' ' << len << '\n';
  return 0;
}
