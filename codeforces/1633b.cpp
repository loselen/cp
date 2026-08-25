#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    string cur;
    cin >> cur;

    unordered_map<char, int> counts;
    for (auto c : cur) {
      counts[c] += 1;
    }

    if (counts['0'] == counts['1']) {
      cout << counts['0'] - 1 << '\n';
    } else {
      cout << min(counts['0'], counts['1']) << '\n';
    }
  }

  return 0;
}
