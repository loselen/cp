#include <bits/stdc++.h>
using namespace std;

#define int long long

const int INF = 4e18;

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;
  cin >> n >> m;

  int from, to;
  cin >> from >> to;

  vector<vector<int>> min_max_idx;
  for (int i = 1; i < n; i++) {
    int cur_from, cur_to;
    cin >> cur_from >> cur_to;

    min_max_idx.push_back({cur_from - to, cur_to - from, i - 1});
    from = cur_from;
    to = cur_to;
  }
  sort(min_max_idx.begin(), min_max_idx.end(),
       [](auto a, auto b) { return a[1] < b[1]; });

  multiset<pair<int, int>> bridge_idx;
  for (int i = 1; i <= m; i++) {
    int cur;
    cin >> cur;
    bridge_idx.insert({cur, i});
  }

  vector<int> res(n - 1);
  for (int i = 0; i < n - 1; i++) {
    auto it = bridge_idx.lower_bound({min_max_idx[i][0], -INF});
    if (it == bridge_idx.end() || (*it).first > min_max_idx[i][1]) {
      cout << "No\n";
      return 0;
    }
    res[min_max_idx[i][2]] = (*it).second;
    bridge_idx.erase(it);
  }

  cout << "Yes\n";
  for (auto r : res) {
    cout << r << ' ';
  }
  cout << '\n';

  return 0;
}
