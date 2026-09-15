#include <bits/stdc++.h>
using namespace std;

#define int long long

int lr(int x, int y) {
  if (x == y) {
    return 0;
  }

  return (y - x) / abs(y - x);
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  freopen("lostcow.in", "r", stdin);
  freopen("lostcow.out", "w", stdout);

  int x, y;
  cin >> x >> y;

  int sign = lr(x, y);
  int res = 0;
  int travel = 1;
  while (true) {
    res += abs(travel - travel / -2);
    if (lr(x + travel, y) != sign) {
      break;
    }
    travel *= -2;
  }
  res -= abs(y - (x + travel));

  cout << res << '\n';

  return 0;
}
