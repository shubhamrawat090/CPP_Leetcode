class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int sum = 0, maxVal = 0;
        int n = weights.size();
        for(int i=0; i<n; i++) {
            sum += weights[i];
            maxVal = max(maxVal, weights[i]);
        }

        int low = maxVal, high = sum;
        int ans = maxVal;
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

    bool isPossible(int mid, vector<int>& weights, int days) {
        int noOfDays = 1;
        int wtSum = 0;

        for(int weight: weights) {
            if(wtSum + weight > mid) {
                noOfDays++;
                wtSum = weight;
            } else {
                wtSum += weight;
            }
        }

        return noOfDays <= days;
    }
};