class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(),
             [](auto a, auto b) { return a[1] - a[0] > b[1] - b[0]; });

        int needed = tasks[0][1];
        int cur_energy = tasks[0][1];
        for (int i = 0; i < tasks.size(); i++) {
            if (cur_energy < tasks[i][1]) {
                needed += tasks[i][1] - cur_energy;
                cur_energy += tasks[i][1] - cur_energy;
            }
            cur_energy -= tasks[i][0];
        }

        return needed;
    }
};
