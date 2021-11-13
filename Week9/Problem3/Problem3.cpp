#include<bits/stdc++.h>

using namespace std;

int main() {

  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  int n;
  cin >> n;

  priority_queue < int > pq;

  for (int i = 0; i < n; ++i) {

    int el;

    cin >> el;

    pq.push(-el);
  }

  int ans = 0;

  while (!pq.empty()) {

    int x = pq.top();

    pq.pop();

    if (pq.empty()) {
      break;
    }

    int y = pq.top();

    x = -x;
    y = -y;

    pq.pop();

    pq.push(-(x + y));

    ans += (x + y);
  }

  cout << ans << '\n';

}
