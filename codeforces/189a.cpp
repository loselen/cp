#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  set<int> allowed;
  for (int i = 0; i < 3; i++) {
    int cur;
    cin >> cur;
    allowed.insert(cur);
  }

  vector<int> dp(n + 1, 0);
  for (auto cut_size : allowed) {
    if (cut_size <= n) {
      dp[cut_size] = 1;
    }
  }

  for (int i = 1; i <= n; i++) {
    for (auto cut_size : allowed) {
      if (i - cut_size >= 0 && dp[i - cut_size] != 0) {
        dp[i] = max(dp[i], dp[i - cut_size] + 1);
      }
    }
  }

  // for (auto d : dp) {
  //   cout << d << ' ';
  // }
  // cout << '\n';

  cout << dp[n] << '\n';

  return 0;
}
