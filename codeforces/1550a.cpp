#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    int cur;
    cin >> cur;

    int cur_odd = 1;
    int res = 0;
    while (cur - cur_odd > 0) {
      cur -= cur_odd;
      res += 1;
      cur_odd += 2;
    }
    res += 1;

    cout << res << '\n';
  }

  return 0;
}
