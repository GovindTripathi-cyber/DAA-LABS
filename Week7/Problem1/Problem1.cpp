// Problem : Implement Dijkstra Algorithm and print shortest paths from source to every other node

#include<bits/stdc++.h>

using namespace std;

vector < int > restorePath(int node, vector < int > & par) {

  vector < int > path;

  for (int i = node; i != -1; i = par[i]) {

    path.push_back(i);
  }

  return path;
}

void Dijkstra(int src, vector < vector < int >> & graph) {

  int n = graph.size();

  vector < int > dist(n, INT_MAX), par(n, -1);

  vector < bool > vis(n, false);

  dist[src] = 0;

  for (int i = 0; i < n; ++i) {

    int v = -1;

    for (int j = 0; j < n; ++j) {

      if (!vis[j] && (v == -1 || dist[v] > dist[j])) {

        v = j;
      }
    }

    if (v == -1 || dist[v] == INT_MAX) {
      break;
    }

    vis[v] = true;

    for (int j = 0; j < n; ++j) {

      if (graph[v][j]) {

        int to = j;

        int cost = graph[v][j];

        if (!vis[to] && dist[to] > dist[v] + cost) {

          dist[to] = dist[v] + cost;

          par[to] = v;
        }
      }
    }

  }

  for (int i = 0; i < n; ++i) {

    vector < int > path = restorePath(i, par);

    for (auto it: path) {
      cout << it + 1 << ' ';
    }

    cout << ": " << dist[i] << '\n';
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

  int src;

  cin >> src;

  Dijkstra(src - 1, graph);
}

int main() {

  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  solve();

  return 0;
}
