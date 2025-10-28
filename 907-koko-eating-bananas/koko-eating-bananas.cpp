class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = 1000000009;
        int ans;
        // Koko wants to eat slowly
        // Check if mid speed possible and store if yes and try lower speed
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(isPossible(mid, piles, h)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }

    bool isPossible(int checkPileSpeed, vector<int>& piles, int hours) {
        long long hoursCounted = 0;
        for(int pile: piles) {
            hoursCounted += ceil(pile * 1.0 / checkPileSpeed);
        }
        return hoursCounted <= hours;
    }
};