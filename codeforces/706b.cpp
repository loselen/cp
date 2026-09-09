#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  vector<int> colas(n);
  for (auto &c : colas) {
    cin >> c;
  }
  sort(colas.begin(), colas.end());

  int q;
  cin >> q;

  for (int i = 0; i < q; i++) {
    int cur_money;
    cin >> cur_money;

    int lo = -1, hi = n;
    while (hi - lo > 1) {
      int mid = (lo + hi) / 2;
      if (colas[mid] > cur_money) {
        hi = mid;
      } else {
        lo = mid;
      }
    }

    cout << hi << '\n';
  }

  return 0;
}
