#include <bits/stdc++.h>
using namespace std;

#define int long long

const int INF = 1e18;

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, k;
  cin >> n >> k;

  vector<int> costs(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> costs[i];
  }

  vector<int> dp(n + 1, INF);
  dp[1] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= k; j++) {
      if (i - j >= 1) {
        dp[i] = min(dp[i], dp[i - j] + abs(costs[i - j] - costs[i]));
      }
    }
  }

  cout << dp[n] << '\n';

  return 0;
}
