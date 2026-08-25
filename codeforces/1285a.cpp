#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  string s;
  cin >> s;

  int right = 0;
  int left = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'L') {
      left -= 1;
    } else {
      right += 1;
    }
  }

  cout << right - left + 1 << '\n';

  return 0;
}
