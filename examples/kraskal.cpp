#include "../kraskal.hh"
#include <bits/stdc++.h>

using namespace std;
using namespace tt;
using Edge = array<int, 3>;

int main(int argc, const char *argv[]) {
  // 頂点・辺の数
  int n, m;
  cin >> n >> m;

  vector<Edge> edges;
  for (int i = 0; i < m; i++) {
    Edge e;
    cin >> e[0] >> e[1] >> e[2];
    edges.push_back(e);
  }

  vector<Edge> result = Kraskal(edges, n);
  for (auto &edge : result) {
    cout << edge[0] << " " << edge[1] << " " << edge[2] << "\n";
  }

  return 0;
}

