class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n = costs.size();

        for (int i = 0; i < n; i++) {
            costs[i][1] = costs[i][1] - costs[i][0];
        }
        sort(costs.begin(), costs.end(),
             [](auto a, auto b) { return a[1] < b[1]; });

        int res = 0;
        for (int i = 0; i < n / 2; i++) {
            res += costs[i][0] + costs[i][1];
        }
        for (int i = n / 2; i < n; i++) {
            res += costs[i][0];
        }

        return res;
    }
};
