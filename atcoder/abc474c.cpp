#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
  int n, q;
  cin >> n >> q;

  int max_idx = n - 1;
  vector<pair<int, int>> mapping(n, {0, 0});
  for (int i = 0; i < n; i++) {
    int cur;
    cin >> cur;
    cur--;
    mapping[cur].first = i;
    mapping[cur].second = cur;
  }

  for (int i = 0; i < q; i++) {
    int to_move;
    cin >> to_move;
    to_move--;
    max_idx++;
    mapping[to_move].first = max_idx + 1;
  }

  sort(mapping.begin(), mapping.end(),
       [](auto a, auto b) { return a.first < b.first; });

  for (auto &pair : mapping) {
    cout << pair.second + 1 << ' ';
  }
  cout << '\n';

  return 0;
}
