#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  vector<int> costs(n);
  for (auto &c : costs) {
    cin >> c;
  }

  vector<int> dp(n, 0);
  dp[0] = 0;
  dp[1] = abs(costs[0] - costs[1]);
  for (int i = 2; i < n; i++) {
    dp[i] = min(dp[i - 1] + abs(costs[i - 1] - costs[i]),
                dp[i - 2] + abs(costs[i - 2] - costs[i]));
  }

  cout << dp[n - 1] << '\n';

  return 0;
}
