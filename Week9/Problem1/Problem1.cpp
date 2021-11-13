// Problem : Using Floyd Algorithm find all pair shortest path

#include <bits/stdc++.h>

using namespace std;

void solve() {

  int n;

  cin >> n;

  vector < vector < int >> dist(n, vector < int > (n, -1));

  for (int i = 0; i < n; ++i) {

    for (int j = 0; j < n; ++j) {

      cin >> dist[i][j];
    }
  }

  for (int k = 0; k < n; ++k) {

    for (int i = 0; i < n; ++i) {

      for (int j = 0; j < n; ++j) {

        if ((dist[i][j] == -1 || dist[i][j] > dist[i][k] + dist[k][j]) && dist[i][k] != -1 && dist[k][j] != -1) {

          dist[i][j] = dist[i][k] + dist[k][j];
        }

      }
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {

      if (dist[i][j] == -1) {
        cout << "INF ";
      } else {
        cout << dist[i][j] << ' ';
      }
    }

    cout << '\n';
  }
}

int main() {

  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  solve();

  return 0;
}
