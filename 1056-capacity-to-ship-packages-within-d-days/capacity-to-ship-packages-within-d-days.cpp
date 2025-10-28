class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int maxVal = 0, sum = 0;
        for(int weight: weights) {
            sum += weight;
            maxVal = max(maxVal, weight);
        }

        int low = maxVal, high = sum, ans;
        while(low <= high) {
            int mid = low + ((high - low) / 2);
            if(isPossible(mid, weights, days)) {
                ans = mid;
                // try smaller weight
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }

    bool isPossible(int checkWeight, vector<int>& weights, int days) {
        int daysCounted = 1;
        int weightSum = 0;
        for(int weight: weights) {
            if(weightSum + weight > checkWeight) {
                daysCounted++;
                weightSum = weight;
            } else {
                weightSum += weight;
            }
        }
        return daysCounted <= days;
    }
};