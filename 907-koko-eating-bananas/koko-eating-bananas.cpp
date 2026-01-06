class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int low = 1, high = 1000000009;
        int ans = 1;
        while(low <= high) {
            int mid = (low + high) / 2;
            if(isPossible(mid, piles, h)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }

    bool isPossible(int speed, vector<int>& piles, int hours) {
        long long hoursTaken = 0;
        for(int pile: piles) {
            hoursTaken += ceil(pile * 1.0 / speed);
        }
        return hoursTaken <= hours;
    }
};