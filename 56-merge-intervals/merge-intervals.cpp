class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        vector<int> mergedInterval = intervals[0];
        for(int i=1; i<intervals.size(); i++) {
            if(intervals[i][0] <= mergedInterval[1]) {
                mergedInterval[1] = max(mergedInterval[1], intervals[i][1]);
            } else {
                ans.push_back(mergedInterval);
                mergedInterval = intervals[i];
            }
        }
        ans.push_back(mergedInterval);
        return ans;
    }
};