class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int pushPosition = -1;
        // insert at apt position
        for (int i = 0; i < intervals.size(); i++) {
            if (newInterval[0] <= intervals[i][0]) {
                pushPosition = i;
                break;
            }
        }

        if (pushPosition == -1) {
            intervals.push_back(newInterval);
        } else {
            intervals.insert(intervals.begin() + pushPosition, newInterval);
        }

        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] <= ans.back()[1]) {
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            } else {
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};