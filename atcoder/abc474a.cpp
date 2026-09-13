#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
  int n;
  cin >> n;

  if (n < 3) {
    cout << n + 1;
  } else {
    cout << n - 1;
  }
  cout << '\n';

  return 0;
}
