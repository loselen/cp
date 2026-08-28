class Solution {
public:
    vector<bool> validness(string ab) {
        int ones = ab[1] - '0';
        int tens = ab[0] - '0';
        int full = tens * 10 + ones;

        vector<bool> res(3, false);
        if (1 <= full && full <= 26) {
            res[2] = true;
        }
        if (tens == 0) {
            res[2] = false;
        }
        if (1 <= ones && ones <= 9) {
            res[1] = true;
        }

        return res;
    }

    int numDecodings(string s) {
        int n = s.size();
        s.insert(s.begin(), '0');

        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        if (s[1] - '0' == 0) {
            return 0;
        }
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            vector<bool> cur_validness = validness(s.substr(i - 1, 2));
            if (cur_validness[1] == false && cur_validness[2] == false) {
                return 0;
            }
            if (cur_validness[1]) {
                dp[i] += dp[i - 1];
            }
            if (cur_validness[2]) {
                dp[i] += dp[i - 2];
            }
        }

        return dp[n];
    }
};
