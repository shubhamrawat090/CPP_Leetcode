class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b) {
            return a[0] < b[0];
        });

        int n = intervals.size();
        int i = 0;
        vector<vector<int>> ans;
        while(i < n) {
            int st = intervals[i][0], ed = intervals[i][1];
            int j = i+1;
            while(j < n && ed >= intervals[j][0]) {
                ed = max(ed, intervals[j][1]);
                j++;
            }
            i = j;
            ans.push_back({st, ed});
        }
        return ans;
    }
};