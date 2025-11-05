class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int maxVal = 0, sum = 0;
        for(int weight: weights) {
            maxVal = max(maxVal, weight);
            sum += weight;
        }

        int low = maxVal, high = sum, ans = maxVal;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(isPossible(mid, weights, days)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }

    bool isPossible(int shipWeight, vector<int>& weights, int days) {
        int daysCounted = 1, weightSum = 0;

        for(int weight: weights) {
            if(weightSum + weight > shipWeight) {
                daysCounted++;
                weightSum = weight;
            } else {
                weightSum += weight;
            }
        }

        return daysCounted <= days;
    }
};