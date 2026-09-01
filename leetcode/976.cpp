class Solution {
public:
  int largestPerimeter(vector<int> &nums) {
    sort(nums.begin(), nums.end());

    int n = nums.size();
    int res = 0;
    for (int i = n - 1; i >= 2; i--) {
      int cur_per = nums[i] + nums[i - 1] + nums[i - 2];
      if (cur_per - nums[i] > nums[i]) {
        res = cur_per;
        break;
      }
    }

    return res;
  }
};
