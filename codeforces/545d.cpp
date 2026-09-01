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
  int not_dissapoint = 0;
  int cur_time = 0;
  for (int i = 0; i < n; i++) {
    if (cur_time > nums[i]) {
      continue;
    } else {
      not_dissapoint += 1;
      cur_time += nums[i];
    }
  }

  cout << not_dissapoint << '\n';

  return 0;
}
