// Problem : Find majority element in array

#include<bits/stdc++.h>

using namespace std;

int main() {

  freopen("input2.txt", "r", stdin);
  freopen("output2.txt", "w", stdout);

  int n;

  cin >> n;

  int arr[n];

  map < int, int > mp;

  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
    mp[arr[i]]++;
  }

  string ans = "NO";

  for (auto it: mp) {

    if (it.second > n / 2) {

      ans = "YES";
      break;
    }
  }

  sort(arr, arr + n);

  cout << ans << '\n';
  cout << arr[(n - 1) / 2] << '\n';
}
