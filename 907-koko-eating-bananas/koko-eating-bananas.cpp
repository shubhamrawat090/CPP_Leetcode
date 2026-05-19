class Solution {
public:
    int minEatingSpeed(vector<int>& arr, int k) {
        // minimum speed = 1, each 1 banana per hour
        // maximum speed = HIGHEST PILE SIZE, EAT THE HIGHEST PILE in 1 hour
        // Ans is between min and max speed
        // APPROACH: Try values in-between(BINARY SEARCH). 
        // If koko can eat for a mid value then save it as answer and try for a smaller value
        // UTILITY FUNCTION: isPossible(mid, arr, k): Can koko eat all bananas with speed = mid and total hours = k
        // suppose: k = 2, bananas: [1, 4, 5], hours = 5
        // bananas[0] = 1, koko eats in 1 hour, 1/2
        // bananas[0] = 4, koko eats in 2 hours, 4/2
        // bananas[0] = 5, koko eats in 3 hours, 5/2 (CEIL VALUE)
        // Total time taken with speed = mid = 2 --> 1 + 2 + 3 = 6 > 5
        // Hence, koko takes more time with this speed so needs to go faster: RETURN FALSE
        // suppose: k = 2, bananas: [1, 4, 5], hours = 7
        // then 6 < 7, it is possible to within k = 7
        int low = 1, high = 1000000000;
        int ans = low;
        while(low <= high) {
            long long mid = (low + high) / 2;
            if(isPossible(mid, arr, k)) {
                ans = mid;
                high = mid-1;
            } else {
                low = mid+1;
            }
        }
        return ans;
    }
    
    bool isPossible(int mid, vector<int>& arr, int k) {
        long long totalHours = 0;
        for(int val: arr) {
            totalHours += ceil(val * 1.0 / mid);
        }
        return totalHours <= k;
    }
};