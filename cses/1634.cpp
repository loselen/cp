#include <bits/stdc++.h>
using namespace std;

#define int long long

const int INF = 1e18;

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, target;
  cin >> n >> target;

  vector<int> coins(n);
  for (auto &c : coins) {
    cin >> c;
  }

  vector<int> dp(target + 1, INF);
  dp[0] = 0;
  for (int i = 1; i <= target; i++) {
    for (auto c : coins) {
      if (i - c >= 0) {
        dp[i] = min(dp[i], dp[i - c] + 1);
        // cout << dp[i] << ' ';
      }
    }
  }
  // cout << '\n';

  if (dp[target] == INF) {
    cout << -1;
  } else {
    cout << dp[target];
  }
  cout << '\n';

  return 0;
}
