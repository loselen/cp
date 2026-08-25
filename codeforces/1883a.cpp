#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    string cur;
    cin >> cur;

    vector<int> display(4);
    for (int j = 0; j < 4; j++) {
      display[j] = cur[j] - '0';
      if (display[j] == 0) {
        display[j] = 10;
      }
    }

    int res = 4 + display[0] - 1;
    for (int j = 1; j < 4; j++) {
      res += abs(display[j] - display[j - 1]);
    }
    cout << res << '\n';
  }

  return 0;
}
