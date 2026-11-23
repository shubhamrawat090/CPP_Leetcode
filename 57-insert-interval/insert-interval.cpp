class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals,
                               vector<int>& newInterval) {
        // push newInterval into intervals array
        // OPTIMIZATION: push new interval into appropriate place, INTERVALS ARE
        // SORTED Then sorting is NOT required
        // sort the intervals array
        // apply the MERGE INTERVALS method
        int n = intervals.size();
        int insertIndex = 0;
        while (insertIndex < n && intervals[insertIndex][0] < newInterval[0]) {
            insertIndex++;
        }

        // cout << insertIndex << " ";

        if (insertIndex == n) {
            intervals.push_back(newInterval);
        } else {
            intervals.insert(intervals.begin() + insertIndex, newInterval);
        }

        return merge(intervals);
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // sort(intervals.begin(), intervals.end());

        int n = intervals.size();
        vector<int> curr = intervals[0];
        vector<vector<int>> ans;

        for (int i = 1; i < n; i++) {
            int currStart = curr[0], currEnd = curr[1];
            int nextStart = intervals[i][0], nextEnd = intervals[i][1];

            // OVERLAP -> merge into curr
            if (nextStart <= currEnd) {
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