#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MOD = 1e9 + 7;

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, target;
  cin >> n >> target;

  vector<int> coins(n);
  for (auto &c : coins) {
    cin >> c;
  }

  vector<int> dp(target + 1, 0);
  dp[0] = 1;
  for (int i = 1; i <= target; i++) {
    for (auto c : coins) {
      if (i - c >= 0) {
        dp[i] = (dp[i] + dp[i - c]) % MOD;
      }
    }
  }

  cout << dp[target] << '\n';

  return 0;
}
