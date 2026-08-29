#include <bits/stdc++.h>
#include <vector>
using namespace std;

#define int long long

pair<vector<int>, vector<int>> construct_prefix(vector<int> &prods) {
  int n = prods.size() - 1; // prods is 1 based

  vector<int> pos(n + 1, 0);
  vector<int> neg(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    pos[i] += pos[i - 1];
    neg[i] += neg[i - 1];
    if (prods[i] > 0) {
      pos[i] += prods[i];
    } else if (prods[i] < 0) {
      neg[i] += prods[i];
    }
  }

  return {pos, neg}; // pos and neg are 1 based
}

const int INF = 1e18;

signed main() {
  ios_base::sync_with_stdio(false);

  int test;
  cin >> test;

  for (int t = 1; t <= test; t++) {
    int n, m;
    cin >> n >> m;

    vector<int> prods(n + 1);
    vector<int> posts(m + 1);
    for (int i = 1; i <= n; i++) {
      cin >> prods[i];
    }
    for (int i = 1; i <= m; i++) {
      cin >> posts[i];
    }
    sort(posts.begin(), posts.end());

    pair<vector<int>, vector<int>> prefix_sums = construct_prefix(prods);
    vector<int> pos = prefix_sums.first;
    vector<int> neg = prefix_sums.second;

    vector<int> dp(m + 1, -INF);
    dp[0] = 0;
    for (int i = 1; i <= m; i++) {
      int flip_prev = posts[i - 1];
      int flip_upto = posts[i];
      int part_sum =
          (pos[flip_upto] - pos[flip_prev]) + (neg[flip_upto] - neg[flip_prev]);
      // compare cur, no flip, yes flip
      dp[i] = max({dp[i], dp[i - 1] + part_sum, dp[i - 1] - part_sum});
    }

    int res = dp[m];

    // compute the trailing > max(posts)
    for (int i = posts.back() + 1; i <= n; i++) {
      res += prods[i];
    }

    cout << res << '\n';
  }

  return 0;
}
