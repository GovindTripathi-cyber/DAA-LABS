// Problem : Find shortest path between source and destination with exactly k edges;

#include<bits/stdc++.h>

using namespace std;

int ans = INT_MAX;

void dfs(int src, int dest, int k, int cost, vector < vector < int >> & graph) {

  int n = graph.size();

  if (src == dest && k == 0) {

    ans = min(ans, cost);
  }

  if (k < 0) {

    return;
  }

  for (int i = 0; i < n; ++i) {

    if (graph[src][i]) {

      dfs(i, dest, k - 1, cost + graph[src][i], graph);
    }
  }
}

void solve() {

  int n;

  cin >> n;

  vector < vector < int >> graph(n, vector < int > (n, 0));

  for (int i = 0; i < n; ++i) {

    for (int j = 0; j < n; ++j) {

      cin >> graph[i][j];
    }
  }

  int src, dest;

  cin >> src >> dest;

  int k;

  cin >> k;

  dfs(src - 1, dest - 1, k, 0, graph);

  if (ans == INT_MAX) {
    cout << "NO path with exactly K edges";
  } else {
    cout << "Shortest Path between " << src << " " << dest << " with exactly " << k << " edges: " << ans << '\n';
  }
}

int main() {

  freopen("input1.txt", "r", stdin);
  freopen("output1.txt", "w", stdout);

  solve();

  return 0;
}
