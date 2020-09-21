#include "../bellman_ford.hh"
#include <bits/stdc++.h>

using namespace std;
using namespace tt;

int main(int argc, const char *argv[]) {
  int n, m, s, g;
  cin >> n >> m >> s >> g;
  vector<Edge> edges;
  for (int i = 0; i < m; ++i) {
    int from, to, cost;
    cin >> from >> to >> cost;
    edges.emplace_back(from, to, cost);
  }

  auto dists = BellmanFord(edges, s, n);
  if (dists[g].has_value()) {
    cout << dists[g].value() << '\n';
  } else {
    cout << "Unreachable" << '\n';
  }
}

