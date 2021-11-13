// Problem : Find number of ways to make a sum of n using given value

#include<bits/stdc++.h>

using namespace std;

int main() {

  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  int n;

  cin >> n;

  int arr[n];

  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }

  int s;
  cin >> s;

  int dp[s + 1][n];

  for (int i = 0; i < n; ++i) {
    dp[0][i] = 1;
  }

  for (int i = 1; i <= s; ++i) {

    for (int j = 0; j < n; ++j) {

      dp[i][j] = 0;

      if (i - arr[j] >= 0) {

        dp[i][j] += dp[i - arr[j]][j];
      }

      if (j >= 1) {

        dp[i][j] += dp[i][j - 1];
      }
    }
  }

  cout << dp[s][n - 1] << '\n';
}
