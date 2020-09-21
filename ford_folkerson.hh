#ifndef FORD_FOLKERSON_HH
#define FORD_FOLKERSON_HH

#include <vector>

namespace tt {

struct MinCostEdge {
  int to, cap, rev;
  MinCostEdge(int to, int cap, int rev) : to(to), cap(cap), rev(rev) {}
};

void AddEdge(std::vector<std::vector<MinCostEdge>> &g, int from, int to,
             int cap) {
  int idx = g[to].size(), rev_idx = g[from].size();
  g[from].emplace_back(to, cap, idx);
  g[to].emplace_back(from, 0, rev_idx);
}

class FordFolkerson {
  std::vector<std::vector<MinCostEdge>> g_;
  std::vector<bool> used_;
  int DFS(int v, int t, int f) {
    if (v == t) {
      return f;
    }

    used_[v] = true;
    for (auto &edge : g_[v]) {
      if (used_[edge.to] || edge.cap <= 0) {
        continue;
      }

      int d = DFS(edge.to, t, f < 0 || f > edge.cap ? edge.cap : f);
      if (d > 0) {
        edge.cap -= d;
        g_[edge.to][edge.rev].cap += d;
        return d;
      }
    }

    return 0;
  }

 public:
  FordFolkerson(std::vector<std::vector<MinCostEdge>> &g)
      : g_(g), used_(g_.size()) {}
  int operator()(int s, int t) {
    int flow = 0, f;
    while (true) {
      fill(used_.begin(), used_.end(), false);
      f = DFS(s, t, -1);
      if (f == 0) {
        return flow;
      }

      flow += f;
    }
  }
};

}  // namespace tt

#endif
