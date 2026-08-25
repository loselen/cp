#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;

    vector<int> nums(k);
    for (auto &j : nums) {
      cin >> j;
    }

    vector<int> incr;
    incr.push_back(nums[0]);
    for (int j = 1; j < k; j++) {
      if (incr.back() <= nums[j]) {
        incr.push_back(nums[j]);
      }
    }

    cout << nums.size() - incr.size() << '\n';
  }

  return 0;
}
