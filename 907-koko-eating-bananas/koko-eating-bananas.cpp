class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxVal = INT_MIN;
        for(int pile: piles) {
            maxVal = max(maxVal, pile);
        }
        int low = 1, high = maxVal;
        int ans = 1;
        while(low <= high) {
            int mid = (low + high) / 2;
            if(isPossible(piles, h, mid)) {
                ans = mid;
                high = mid-1;
            } else {
                low = mid+1;
            }
        }
        return ans;
    }

    bool isPossible(vector<int>& piles, int hours, int speed) {
        long long hoursTaken = 0;
        for(int pile: piles) {
            hoursTaken += ceil(pile * 1.0/speed);
        }
        return hoursTaken <= hours;
    }
};