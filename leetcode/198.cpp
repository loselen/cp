class Solution {
public:
  const int INF = 1e9;

  int rob(vector<int> &nums) {
    int n = nums.size();
    if (n <= 1) {
      return nums[0];
    }

    nums.insert(nums.begin(), 0);

    vector<int> dp(n + 1, -INF);
    dp[0] = 0;
    dp[1] = nums[1];
    for (int i = 2; i <= n; i++) {
      dp[i] = max({dp[i], dp[i - 1], nums[i] + dp[i - 2]});
    }

    return dp[n];
  }
};
