#include <bits/stdc++.h>
using namespace std;

#define int long long

const int INF = 4e18;

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  freopen("speeding.in", "r", stdin);
  freopen("speeding.out", "w", stdout);

  int n, m;
  cin >> n >> m;

  vector<int> maxs;
  for (int i = 0; i < n; i++) {
    int len, cur_max;
    cin >> len >> cur_max;

    for (int j = 0; j < len; j++) {
      maxs.push_back(cur_max);
    }
  }

  vector<int> speeds;
  for (int i = 0; i < m; i++) {
    int len, cur_speed;
    cin >> len >> cur_speed;

    for (int j = 0; j < len; j++) {
      speeds.push_back(cur_speed);
    }
  }

  int max_val = -INF;
  for (int i = 0; i < 100; i++) {
    max_val = max(max_val, speeds[i] - maxs[i]);
  }

  if (max_val < 0) {
    cout << 0;
  } else {
    cout << max_val;
  }
  cout << '\n';

  return 0;
}
