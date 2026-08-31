class Solution {
public:
    int climbStairs(int n) {
        // return recursive(n);
        // vector<int> dp(n+1, -1);
        // return memoized(n, dp);
        // return tabulate(n);
        return spaceOptimized(n);
    }

    int spaceOptimized(int n) {
        int prev2 = 1; 
        int prev = 1;

        for(int i=2; i<=n; i++) {
            int curr = prev + prev2;
            prev2 = prev;
            prev = curr;
        }

        return prev;
    }

    int tabulate(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        if (n + 1 >= 2) {
            dp[1] = 1;
        }

        for(int i=2; i<=n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }

        return dp[n];
    }

    int memoized(int n, vector<int>& dp) {
        if (n == 0)
            return 1;
        if (n < 0)
            return 0;

        if (dp[n] != -1)
            return dp[n];

        int oneStep = memoized(n - 1, dp);
        int twoSteps = memoized(n - 2, dp);

        return dp[n] = oneStep + twoSteps;
    }

    int recursive(int n) {
        if (n == 0)
            return 1;
        if (n < 0)
            return 0;

        int oneStep = recursive(n - 1);
        int twoSteps = recursive(n - 2);

        return oneStep + twoSteps;
    }
};