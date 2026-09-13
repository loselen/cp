#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
  int n;
  cin >> n;

  vector<int> nums(n);
  for (auto &num : nums) {
    cin >> num;
  }

  int cur_cap = 10;
  for (int i = 0; i < n; i++) {
    if (nums[i] > cur_cap) {
      cout << "No\n";
      return 0;
    }
    if (i + 1 == cur_cap) {
      cur_cap += 10;
    }
  }

  cout << "Yes\n";

  return 0;
}
