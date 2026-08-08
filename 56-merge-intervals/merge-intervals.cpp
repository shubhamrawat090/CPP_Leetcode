class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        vector<int> interval = intervals[0];
        vector<vector<int>> result;
        for (int i = 1; i < n; i++) {
            vector<int> currInterval = intervals[i];
            int a = interval[0], b = interval[1];
            int c = currInterval[0], d = currInterval[1];
            if (c <= b) {
                // merging
                interval[1] = max(b, d);
            } else {
                result.push_back(interval);
                interval = currInterval;
            }
        }

        result.push_back(interval);
        return result;
    }
};