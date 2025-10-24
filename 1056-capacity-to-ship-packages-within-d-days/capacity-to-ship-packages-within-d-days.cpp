class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int maxVal = 0, sum = 0;
        for(int weight: weights) {
            sum += weight;
            maxVal = max(weight, maxVal);
        }

        int low = maxVal, high = sum, ans = 0;
        while(low <= high) {
            int mid = (low + high) / 2;
            if(isPossible(mid, weights, days)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }

    bool isPossible(int shipWeight, vector<int>& weights, int daysReq) {
        int days = 1;
        int weight = 0;

        for(int i=0; i<weights.size(); i++) {
            if(weight + weights[i] <= shipWeight) {
                weight += weights[i];
            } else {
                days++;
                weight = weights[i];
            }
        }

        return days <= daysReq;
    }
};