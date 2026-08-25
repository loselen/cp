#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    int num;
    cin >> num;

    int sum = 0;
    for (int j = 0; j < num; j++) {
      int cur;
      cin >> cur;
      sum += cur;
    }

    if (sum % num == 0) {
      cout << sum / num;
    } else {
      cout << sum / num + 1;
    }
    cout << '\n';
  }

  return 0;
}
