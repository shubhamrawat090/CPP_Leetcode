class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int count = 0;
        int n = intervals.size();
        unordered_set<int> skippedIndices;
        for (int i = 1; i < n; i++) {
            vector<int> currInterval = intervals[i];
            vector<int> prevInterval = intervals[i - 1];
            for (int j = i - 1; j >= 0; j--) {
                if (skippedIndices.count(j) == 0) {
                    prevInterval = intervals[j];
                    break;
                }
            }
            int a = prevInterval[0], b = prevInterval[1];
            int c = currInterval[0], d = currInterval[1];
            if (c < b) {
                // FAILS: [[1,11],[1,100],[2,12],[11,22]] is we always remove
                // ith interval Always remove the interval with HIGHER END TIME
                if (b > d) {
                    skippedIndices.insert(i - 1);
                } else {
                    skippedIndices.insert(i);
                }
                count++;
            }
        }
        return count;
    }
};