class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime,
                      vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>> combined;
        for (int i = 0; i < n; i++) {
            combined.push_back({startTime[i], endTime[i], profit[i]});
        }
        sort(combined.begin(), combined.end(),
             [](auto a, auto b) { return a[1] < b[1]; });
        vector<int> dp(n);
        dp[0] = combined[0][2];
        for (int i = 1; i < n; i++) {
            int lo = -1, hi = i;
            while (hi - lo > 1) {
                int mid = (lo + hi) / 2;
                if (combined[i][0] < combined[mid][1]) {
                    hi = mid;
                } else {
                    lo = mid;
                }
            }
            if (hi - 1 == -1) {
                dp[i] = max(dp[i - 1], combined[i][2]);
                continue;
            }
            dp[i] = max(dp[i - 1], combined[i][2] + dp[hi - 1]);
        }

        return dp[n - 1];
    }
};
