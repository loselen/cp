#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  vector<int> nums(n);
  for (auto &n : nums) {
    cin >> n;
  }

  vector<int> nums_sort = nums;
  sort(nums_sort.begin(), nums_sort.end());

  for (int i = 0; i < n; i++) {
    int q = nums[i];

    int lo = 0, hi = n;
    while (lo < hi) {
      int mid = (lo + hi) / 2;
      if (nums_sort[mid] > q) {
        hi = mid;
      } else {
        lo = mid + 1;
      }
    }

    int idx = lo;

    cout << 1 + n - idx << ' ';
  }
  cout << '\n';

  return 0;
}
