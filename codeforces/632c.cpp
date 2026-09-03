#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  vector<string> strs(n);
  for (auto &s : strs) {
    cin >> s;
  }
  sort(strs.begin(), strs.end(),
       [](string a, string b) { return a + b < b + a; });

  string res = "";
  for (int i = 0; i < n; i++) {
    res += strs[i];
  }

  cout << res << '\n';

  return 0;
}
