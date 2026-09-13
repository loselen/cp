#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
  int n;
  cin >> n;

  vector<int> a(n);
  vector<int> b(n);
  for (auto &i : a) {
    cin >> i;
  }
  for (auto &i : b) {
    cin >> i;
  }

  vector<int> diffs(n, 0);
  for (int i = 0; i < n; i++) {
    diffs[i] = a[i] - b[i];
  }

  bool is_valid = false;
  for (int i = 0; i < n; i++) {
    if (diffs[i] > 0) {
      is_valid = true;
      break;
    }
  }

  if (!is_valid) {
    cout << "No\n";
    return 0;
  }

  vector<int> answers(n, 0);
  for (int i = 0; i < n; i++) {
    if (diffs[i] <= 0) {
      answers[i] = 1;
    } else {
      answers[i] = 1e18;
    }
  }

  double sum = 0.0;
  for (int i = 0; i < n; i++) {
    sum += static_cast<double>(answers[i]) * static_cast<double>(diffs[i]);
  }

  if (sum <= 0.0) {
    cout << "No\n";
    return 0;
  } else {
    cout << "Yes\n";

    for (auto ans : answers) {
      cout << ans << ' ';
    }
    cout << '\n';
  }

  return 0;
}
