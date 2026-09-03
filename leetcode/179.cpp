class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> nums_str;
        for (auto num : nums) {
            nums_str.push_back(to_string(num));
        }
        sort(nums_str.begin(), nums_str.end(),
             [](string a, string b) { return a + b > b + a; });

        if (nums_str[0] == "0") {
            return "0";
        }

        string res = "";
        for (auto& ns : nums_str) {
            res += ns;
        }

        return res;
    }
};
