// Problem : Given a set of elements, you have to partition the set into two subsets such that the sum of
// elements in both subsets is same. Design an algorithm and implement it using a program to solve
// this problem.

#include<bits/stdc++.h>

using namespace std;

int main() {

  freopen("input1.txt", "r", stdin);
  freopen("output1.txt", "w", stdout);

  int n;

  cin >> n;

  int arr[n];

  int sum = 0;

  for (int i = 0; i < n; ++i) {

    cin >> arr[i];

    sum += arr[i];
  }

  vector < bool > dp(sum + 1, false);

  dp[0] = true;

  for (int i = 0; i < n; ++i) {

    for (int j = sum; j >= 0; --j) {

      if (j - arr[i] >= 0 && dp[j - arr[i]]) {

        dp[j] = true;
      }
    }
  }

  if ((sum & 1) || !dp[sum / 2]) {
    cout << "NO\n";
  } else {
    cout << "YES\n";
  }
}
