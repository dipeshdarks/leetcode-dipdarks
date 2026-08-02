class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;

        for (auto &interval : intervals) {
            if (ans.empty() || ans.back()[1] < interval[0]) {
                // No overlap
                ans.push_back(interval);
            } else {
                // Overlap, merge
                ans.back()[1] = max(ans.back()[1], interval[1]);
            }
        }

        return ans;
    }
};