#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  vector<int> nums(n);
  for (auto &num : nums) {
    cin >> num;
  }

  sort(nums.begin(), nums.end());

  int min_coin = 0;
  for (int i = 1; i < n; i++) {
    int to_add = nums[i - 1] - nums[i] + 1;
    if (to_add > 0) {
      min_coin += to_add;
      nums[i] += to_add;
    }
  }

  // for (auto num : nums) {
  //   cout << num << ' ';
  // }
  // cout << '\n';

  cout << min_coin << '\n';

  return 0;
}
