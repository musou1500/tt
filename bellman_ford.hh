#ifndef BELLMAN_FORD_HH
#define BELLMAN_FORD_HH

#include <optional>
#include <vector>

namespace tt {

struct Edge {
  int from, to, cost;
  Edge(int from, int to, int cost) : from(from), to(to), cost(cost) {}
};

std::vector<std::optional<int>> BellmanFord(std::vector<Edge> &edges, int src,
                                            int node_size) {
  std::vector<std::optional<int>> dists(node_size);
  dists[src] = 0;
  for (int i = 0; i < node_size; ++i) {
    for (auto &e : edges) {
      if (!dists[e.from].has_value()) {
        continue;
      }

      int dist = dists[e.from].value() + e.cost;
      if (!dists[e.to].has_value() || dists[e.to].value() > dist) {
        dists[e.to] = dist;
        if (i == node_size - 1) {
          break;
        }
      }
    }
  }

  return dists;
}
}  // namespace tt

#endif
