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

  int sum = 0;
  for (int i = n - 1; i - 1 >= 0; i--) {
    if (nums[i] - nums[i - 1] <= 1) {
      int cur_can = nums[i - 1];
      i -= 2;
      while (i - 1 >= 0) {
        if (nums[i] - nums[i - 1] <= 1) {
          sum += cur_can * nums[i - 1];
          i -= 1;
          break;
        }
        i -= 1;
      }
    }
  }

  cout << sum << '\n';

  return 0;
}
