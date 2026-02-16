class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        vector<int> temp;
        temp = intervals[0];
        for(int i=1; i<intervals.size(); i++) {
            // temp: (a, b),  intervals[i]: (c, d)
            // c(intervals[i][0]) <= b(temp[1]) => merge
            // else => push interval in ans, update temp = intervals[i] 
            if(intervals[i][0] <= temp[1]) {
                temp[1] = max(temp[1], intervals[i][1]);
            } else {
                ans.push_back(temp);
                temp = intervals[i];
            }
        }
        ans.push_back(temp);
        return ans;
    }
};