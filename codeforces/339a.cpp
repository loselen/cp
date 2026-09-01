#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string exp;
  cin >> exp;
  exp.insert(exp.begin(), '0');

  vector<int> nums;
  int n = exp.size() - 1;
  for (int i = 1; i <= n; i += 2) {
    nums.push_back(exp[i] - '0');
  }

  sort(nums.begin(), nums.end());
  for (int i = 0; i < nums.size() - 1; i++) {
    cout << nums[i] << '+';
  }
  cout << nums.back() << '\n';

  return 0;
}
