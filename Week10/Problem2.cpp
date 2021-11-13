// Problem : Given a long list of tasks. Each task takes specific time to accomplish it and each task has a
// deadline and profit associated with it. You have to design an algorithm and implement it using a program to
// find maximum number of tasks that can be completed without crossing their deadlines and also
// find list of selected tasks.

#include<bits/stdc++.h>

using namespace std;

struct job {

  int id, deadline, profit;
};

job getJob(int id, int profit, int deadline) {

  job j;

  j.id = id;
  j.deadline = deadline;
  j.profit = profit;

  return j;
}

bool comp(job & a, job & b) {

  return a.profit > b.profit;
}

void solve() {

  int n;

  cin >> n;

  vector < job > v(n);

  int maxtime = 0;

  vector < int > deadline(n), profit(n);

  for (int i = 0; i < n; ++i) {

    cin >> profit[i];
  }

  for (int i = 0; i < n; ++i) {

    cin >> deadline[i];

    maxtime = max(maxtime, deadline[i]);
  }

  for (int i = 0; i < n; ++i) {

    v[i] = getJob(i + 1, profit[i], deadline[i]);
  }

  sort(v.begin(), v.end(), comp);

  vector < bool > is_occupied(maxtime, false);

  vector < int > ans;

  for (int i = 0; i < n; ++i) {

    job j = v[i];

    for (int k = j.deadline - 1; k >= 0; --k) {

      if (!is_occupied[k]) {

        is_occupied[k] = true;

        ans.push_back(j.id);

        break;
      }
    }
  }

  cout << "Number of Non Conflicting activities: " << ans.size() << '\n';

  cout << "Job id for maximum profit :\n";

  for (auto it: ans) {
    cout << it << ' ';
  }
}

int main() {

  freopen("input1.txt", "r", stdin);
  freopen("output1.txt", "w", stdout);

  solve();
  return 0;
}
