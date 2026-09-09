class Solution {
public:
  int searchInsert(vector<int> &nums, int target) {
    int n = nums.size();
    int lo = -1, hi = n;
    while (hi - lo > 1) {
      int mid = (lo + hi) / 2;
      if (nums[mid] >= target) {
        hi = mid;
      } else {
        lo = mid;
      }
    }

    return hi;
  }
};
