#ifndef DIJKSTRA_HH
#define DIJKSTRA_HH

#include <array>
#include <queue>
#include <utility>
#include <vector>

namespace tt {
class Dijkstra {
  using QItem = std::pair<int, int>;

 public:
  std::vector<int> minDistance(std::vector<std::array<int, 3>> &edges, int n,
                               int src) {
    std::vector<int> costs(n, -1);
    costs[src] = 0;

    // 各ノードの隣接ノードとその距離を初期化
    std::vector<std::vector<std::pair<int, int>>> distances(n);
    for (auto &edge : edges) {
      int n1 = edge[0], n2 = edge[1], d = edge[2];
      distances[n1].push_back({n2, d});
    }

    std::vector<bool> used(n, false);
    std::priority_queue<QItem, std::vector<QItem>, std::greater<QItem>> q;
    q.push({0, src});

    while (!q.empty()) {
      // 未確定で，コストの一番低いノードを選択する
      auto [min_cost, min_idx] = q.top();
      q.pop();

      // 選択したノードは確定とする
      used[min_idx] = true;

      // 選択したノードの隣接ノードについて，そのコストを再計算する
      for (auto &p : distances[min_idx]) {
        int new_cost = min_cost + p.second;
        if (costs[p.first] < 0 || costs[p.first] > new_cost) {
          costs[p.first] = new_cost;
          q.push({new_cost, p.first});
        }
      }
    }

    return costs;
  }
};

}  // namespace tt

#endif
