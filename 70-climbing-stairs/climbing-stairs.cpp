class Solution {
public:
    int climbStairs(int n) {
        // return recursive(n);
        vector<int> dp(n+1, -1);
        return memoized(n, dp);
    }

    int memoized(int n, vector<int>& dp) {
        if(n == 0) return 1;
        if(n < 0) return 0;

        if(dp[n] != -1) return dp[n];

        int oneStep = memoized(n-1, dp);
        int twoSteps = memoized(n-2, dp);

        return dp[n] = oneStep + twoSteps;
    }

    int recursive(int n) {
        if(n == 0) return 1;
        if(n < 0) return 0;

        int oneStep = recursive(n-1);
        int twoSteps = recursive(n-2);

        return oneStep + twoSteps;
    }
};