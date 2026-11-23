class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        int n = intervals.size();
        vector<int> curr = intervals[0];
        vector<vector<int>> ans;

        for(int i=1; i<n; i++) {
            int currStart = curr[0], currEnd = curr[1];
            int nextStart = intervals[i][0], nextEnd = intervals[i][1];

            // OVERLAP -> merge into curr
            if(nextStart <= currEnd) {
                curr[1] = max(currEnd, nextEnd);
            }
            // NO OVERLAP -> push curr in ans, set curr = intervals[i]
            else {
                ans.push_back(curr);
                curr = intervals[i];
            }
        }

        ans.push_back(curr); // add the last meeting as well

        return ans;
    }
};