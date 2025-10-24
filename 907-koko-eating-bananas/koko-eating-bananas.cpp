class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int low = 1, high = 1000000009, ans;
        while(low <= high) {
            int mid = (low + high) / 2;
            if(isPossible(mid, piles, n, h)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }

    bool isPossible(int targetPile, vector<int>& piles, int n, int hoursReq) {
        long long hourCalc = 0;
        for(int pile: piles) {
            hourCalc += ceil(pile * 1.0 / targetPile);
        }
        return hourCalc <= hoursReq;
    }
};