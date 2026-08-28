class Solution {
public:
  const int INF = 1e9;

  int rob(vector<int> &nums) {
    int n = nums.size();
    if (n <= 1) {
      return nums[0];
    }

    nums.insert(nums.begin(), 0);

    // ws = with start, wos = without start

    vector<int> dp_ws(n + 1, -INF);
    dp_ws[0] = 0;
    dp_ws[1] = nums[1];
    for (int i = 2; i <= n - 1; i++) {
      dp_ws[i] = max({dp_ws[i], dp_ws[i - 1], dp_ws[i - 2] + nums[i]});
    }
    dp_ws[n] = max(dp_ws[n], dp_ws[n - 1]);

    vector<int> dp_wos(n + 1, -INF);
    dp_wos[0] = 0;
    dp_wos[1] = 0;
    for (int i = 2; i <= n; i++) { // for this case, we do until n because for
                                   // the last house, we can choose to steal or
                                   // not since the first house is not stolen
      dp_wos[i] = max({dp_wos[i], dp_wos[i - 1], dp_wos[i - 2] + nums[i]});
    }

    return max(dp_ws[n], dp_wos[n]);
  }
};
