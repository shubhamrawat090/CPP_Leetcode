class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        // int ans = recursive(coins, amount, n);
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, -1));
        int ans = memoized(coins, amount, n, dp);
        return ans == INT_MAX ? -1 : ans;
    }

    int memoized(vector<int>& coins, int amount, int n,
                 vector<vector<int>>& dp) {
        if (amount == 0)
            return 0; // 0 amounts can be made up by using 0 coins

        if (n == 1) {
            return amount % coins[n - 1] == 0 ? amount / coins[n - 1] : INT_MAX;
        }

        if (dp[n][amount] != -1)
            return dp[n][amount];

        if (amount >= coins[n - 1]) {
            int notPick = memoized(coins, amount, n - 1, dp);
            int pickCall = memoized(coins, amount - coins[n - 1], n, dp);
            int pick = pickCall == INT_MAX ? INT_MAX : 1 + pickCall;
            return dp[n][amount] = min(pick, notPick);
        } else {
            int notPick = memoized(coins, amount, n - 1, dp);
            return dp[n][amount] = notPick;
        }
    }

    int recursive(vector<int>& coins, int amount, int n) {
        if (amount == 0)
            return 0; // 0 amounts can be made up by using 0 coins

        if (n == 0)
            return INT_MAX; // Unsure??

        int notPick = recursive(coins, amount, n - 1);
        int pick = 0;
        if (amount >= coins[n - 1]) {
            pick = 1 + recursive(coins, amount - coins[n - 1], n);
        }
        return min(pick, notPick);
    }
};