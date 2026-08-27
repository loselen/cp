#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MOD = 1e9 + 7;

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  if (n == 0) {
    cout << 1 << '\n';
    return 0;
  } else if (n <= 4) {
    cout << static_cast<int>(pow(2, n - 1)) << '\n';
    return 0;
  }

  vector<int> dp(n + 1, 0);
  dp[0] = 1;
  dp[1] = 1;
  dp[2] = 2;
  dp[3] = 4;
  dp[4] = 8;
  dp[5] = 16;

  for (int i = 6; i <= n; i++) {
    for (int j = 1; j <= 6; j++) {
      dp[i] += dp[i - j];
    }
    dp[i] %= MOD;
  }

  cout << dp[n] << '\n';

  return 0;
}
