// Problem : Use Kruskal algorithm to find Minimum Spanning Tree.

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

bool comp(edge & a, edge & b) {

  return a.cost < b.cost;
}

// DSU
int find(int a, vector < int > & par) {

  if (par[a] == -1) {
    return a;
  }

  return par[a] = find(par[a], par);
}

void merge(int a, int b, vector < int > & par, vector < int > & sz) {

  a = find(a, par);

  b = find(b, par);

  if (a != b) {

    if (sz[a] < sz[b]) {

      swap(a, b);
    }

    par[b] = a;

    sz[a] += sz[b];
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

  vector < int > par(n, -1), sz(n, 1);

  vector < edge > edges;

  for (int i = 0; i < n; ++i) {

    for (int j = i + 1; j < n; ++j) {

      if (graph[i][j] != 0) {

        edges.push_back(getEdge(i, j, graph[i][j]));
      }
    }
  }

  sort(edges.begin(), edges.end(), comp);

  int minimum_weight = 0;

  for (int i = 0; i < (int) edges.size(); ++i) {

    edge e = edges[i];

    if (find(e.u, par) != find(e.v, par)) {

      minimum_weight += e.cost;

      merge(e.u, e.v, par, sz);
    }
  }

  cout << "Minimum Spanning Weight: " << minimum_weight << '\n';
}

int main() {

  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  solve();

  return 0;
}
