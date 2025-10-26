class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // Atleast 1 banana/hour of speed 
        // Atmost 10^9 banana/hour of speed - A/c to highest value of piles[i] in constraints
        // The ans should be between this only
        int low = 1, high = 1000000009;
        int ans = 0;

        // Pick a number(mid) b/w low->high and check if it is possible to all in mid/hour speed.
        // If yes then try for a lower speed. Otherwise, try for higher speed
        while(low <= high) {
            int mid = low + ((high - low) / 2);
            if(isPossible(mid, piles, h)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }

    bool isPossible(int checkSpeed, vector<int>& piles, int hours) {
        // we know speed = dist/time => checkSpeed = piles[i]/hoursTaken
        // So, hoursTaken = piles[i] / checkSpeed
        // There can be this scenario -> hoursTaken = 3/2 = 1.5 hours. 
        // Since, Koko will not eat from other piles in the remainder of 2nd hour. 
        // Therefore 1.5 hrs is rounded off to 2 hours
        // WE TAKE CEIL VALUE
        long long hoursTakenSum = 0;
        for(int pile: piles) {
            hoursTakenSum += ceil(pile * 1.0 / checkSpeed);
        }
        return hoursTakenSum <= hours;
    }
};