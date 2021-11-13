// Problem:Given a list of activities with their starting time and finishing time. Your goal is to select
// maximum number of activities that can be performed by a single person such that selected
// activities must be non-conflicting. Any activity is said to be non-conflicting if starting time of an
// activity is greater than or equal to the finishing time of the other activity. Assume that a person
// can only work on a single activity at a time

#include<bits/stdc++.h>

using namespace std;

bool comp(pair < pair < int, int > , int > & a, pair < pair < int, int > , int > & b) {

  return a.first.second < b.first.second;
}

void solve() {

  int n;

  cin >> n;

  vector < pair < pair < int, int > , int >> v(n);

  for (int i = 0; i < n; ++i) {

    cin >> v[i].first.first;

    v[i].second = i + 1;
  }

  for (int i = 0; i < n; ++i) {

    cin >> v[i].first.second;

    v[i].second = i + 1;
  }

  sort(v.begin(), v.end(), comp);

  vector < int > ans;

  int endtime = 0;

  for (int i = 0; i < n; ++i) {

    if (endtime < v[i].first.first) {

      ans.push_back(v[i].second);

      endtime = v[i].first.second;
    }
  }

  cout << ans.size() << '\n';

  for (auto it: ans) {
    cout << it << ' ';
  }

  cout << '\n';

}

int main() {

  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  solve();

  return 0;

}
