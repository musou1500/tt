#ifndef UNION_FIND_HH
#define UNION_FIND_HH

#include <vector>

namespace tt {
class UnionFind {
  std::vector<int> graph_;
  std::vector<int> sizes_;

 public:
  UnionFind(int n) : sizes_(n, 1), graph_(n) {
    for (int i = 0; i < n; ++i) {
      graph_[i] = i;
    }
  };

  int Root(int key) {
    if (graph_[key] == key) {
      return key;
    } else {
      return graph_[key] = Root(graph_[key]);
    }
  }

  bool Same(int key1, int key2) { return Root(key1) == Root(key2); }

  void Unite(int key1, int key2) {
    if (Same(key1, key2)) {
      return;
    }

    int root1 = Root(key1);
    int root2 = Root(key2);
    int size = Size(root1) + Size(root2);
    graph_[root1] = root2;
    sizes_[root2] = size;
  }

  int Size(int key) {
    int root = Root(key);
    return sizes_[root];
  }
};

}  // namespace tt

#endif
