class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int maxVal = INT_MIN, sum = 0;
        for(int wt: weights) {
            sum += wt;
            maxVal = max(maxVal, wt);
        }

        int low = maxVal, high = sum;
        int ans = -1;
        while(low <= high) {
            int mid = (low + high) / 2;
            if(isPossible(weights, days, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }

    bool isPossible(vector<int>& weights, int& days, int& capacity) {
        int weight = 0; 
        int day = 1;
        int n = weights.size();
        for(int i=0; i<n; i++) {
            if(weight + weights[i] <= capacity) {
                weight += weights[i];
            } else {
                day++;
                weight = 0;
                i--;
            }
        }
        return day <= days;
    }
};