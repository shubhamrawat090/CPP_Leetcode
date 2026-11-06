class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        // duration 2, [1, 4]
        // 1   2   3   4   5
        // -----       -----
        // counted 1, 2, 4, 5
        // start: times[i], end = times[i] + duration - 1. Count: end-start+1

        // duration 2, [1, 2]
        // 1   2   3   4
        // ---------
        // counted 1, 2, 3
        // So, from 1, I could go 2. But since 2 is the next point in times arr
        // we only take 1, so end = times[i] + duration - 1 - 1

        int totalTime = 0;
        int n = timeSeries.size();

        for (int i = 0; i < n; i++) {
            int start = timeSeries[i];
            int end = timeSeries[i] + duration - 1;
            
            if (i < n - 1) {
                if (end >= timeSeries[i + 1])
                    end = timeSeries[i + 1] - 1;
            }

            int count = end - start + 1;
            totalTime += count;
        }

        return totalTime;
    }
};