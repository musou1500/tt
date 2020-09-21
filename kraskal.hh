#ifndef KRASKAL_HH
#define KRASKAL_HH

#include <array>
#include <queue>
#include <vector>

// **requires union_find**
#include "./union_find.hh"

namespace tt {

std::vector<std::array<int, 3>> Kraskal(std::vector<std::array<int, 3>> &edges,
                                        int node_size) {
  UnionFind uf(node_size);

  // from, to, cost
  using Edge = std::array<int, 3>;

  auto compare = [](const Edge &a, const Edge &b) { return a[2] < b[2]; };
  // 入力された辺を優先度付きキューへ入れる
  std::priority_queue<Edge, std::vector<Edge>, decltype(compare)> edge_q(
      compare);
  for (auto &e : edges) {
    edge_q.push(e);
  }

  // キューから取り出し，閉路が出来なければ追加
  std::vector<Edge> result;
  while (!edge_q.empty()) {
    auto &edge = edge_q.top();
    if (!uf.Same(edge[0], edge[1])) {
      result.push_back(edge);
      uf.Unite(edge[0], edge[1]);
    }

    edge_q.pop();
  }

  return result;
}

}  // namespace tt

#endif

