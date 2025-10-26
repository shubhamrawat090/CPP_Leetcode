class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int N = weights.size(), sum = 0, maxVal = 0;
        for(int i=0; i<N; i++) {
            if(weights[i] > maxVal) {
                maxVal = weights[i];
            }
            sum += weights[i];
        }

        int low = maxVal, high = sum, ans;
        while(low <= high) {
            int mid = low + ((high - low) / 2);
            if(isPossible(mid, weights, N, days)) {
                ans = mid;
                high = mid - 1; // try a smaller weight
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }

    bool isPossible(int checkWeight, vector<int>& weights, int N, int days) {
        // If we can add weights[i] to the curr day's weight sum then we do it.
        // Otherwise, we do not add weights[i] and move to next day
        // For the next day we start with weightSum = weights[i]; // Because that weight wasn't added in prev day
        int daysCounted = 1; // we start with day 1
        int weightSum = 0;
        for(int i = 0; i < N; i++) {
            // Can we add to curr day's wtSum??
            if(weightSum + weights[i] <= checkWeight) {
                weightSum += weights[i];
            } else {
                daysCounted++;
                weightSum = weights[i];
                // Need to add weights[i] to next day
            }
        }
        return daysCounted <= days;
    }
};