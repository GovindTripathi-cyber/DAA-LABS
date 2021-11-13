// Problem : Implement Bellman Ford Algorithm and print shortest paths from source to every other node

#include<bits/stdc++.h>

using namespace std;

struct edge {

  int u, v, cost;
};

edge getEdge(int u, int v, int cost) {

  edge e;

  e.u = u;
  e.v = v;
  e.cost = cost;

  return e;
}

vector < int > restorePath(int node, vector < int > & par) {

  vector < int > path;

  for (int i = node; i != -1; i = par[i]) {

    path.push_back(i);
  }

  return path;
}

void BellmanFord(int src, vector < edge > & edges, int n) {

  vector < int > par(n, -1), dist(n, INT_MAX);

  dist[src] = 0;

  for (int i = 0; i < n - 1; ++i) {

    for (int j = 0; j < edges.size(); ++j) {

      edge e = edges[j];

      if (dist[e.u] < INT_MAX) {

        if (dist[e.v] > dist[e.u] + e.cost) {

          dist[e.v] = dist[e.u] + e.cost;

          par[e.v] = e.u;
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

  vector < edge > edges;

  for (int i = 0; i < n; ++i) {

    for (int j = 0; j < n; ++j) {

      int el;

      cin >> el;

      if (el) {
        edges.push_back(getEdge(i, j, el));
      }
    }
  }

  int src;

  cin >> src;

  BellmanFord(src - 1, edges, n);
}

int main() {

  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  solve();

  return 0;
}
