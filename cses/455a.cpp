#include <bits/stdc++.h>
using namespace std;

#define int long long

const int INF = 1e18;

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  unordered_map<int, int> counts_map;
  int cur_max = -INF;
  for (int i = 1; i <= n; i++) {
    int cur;
    cin >> cur;
    counts_map[cur] += 1;
    cur_max = max(cur_max, cur);
  }
  // cout << "max: " << cur_max << '\n';

  vector<int> counts(cur_max + 1, 0);
  for (auto pair : counts_map) {
    // cout << pair.first << ": " << pair.second << '\n';
    counts[pair.first] = pair.second;
  }

  vector<int> dp(cur_max + 1, -INF);
  dp[0] = 0;
  dp[1] = counts[1];
  for (int i = 2; i <= cur_max; i++) {
    dp[i] = max({dp[i], dp[i - 1], i * counts[i] + dp[i - 2]});
  }

  cout << dp[cur_max] << '\n';

  return 0;
}
