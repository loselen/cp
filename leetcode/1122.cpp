class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> ranking;
        for (int i = 0; i < arr2.size(); i++) {
            ranking[arr2[i]] = i + 1;
        }

        vector<int> both_nums;
        multiset<int> others;
        for (int i = 0; i < arr1.size(); i++) {
            if (ranking[arr1[i]] > 0) {
                both_nums.push_back(arr1[i]);
            } else {
                others.insert(arr1[i]);
            }
        }

        sort(both_nums.begin(), both_nums.end(),
             [&](int a, int b) { return ranking[a] < ranking[b]; });

        vector<int> res = both_nums;
        for (auto n : others) {
            res.push_back(n);
        }

        return res;
    }
};
