class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // int res = recursive(coins, 0, amount);
        // return res == INT_MAX ? -1 : res;

        // vector<vector<int>> dp(coins.size() + 1, vector<int>(amount + 1,
        // -1)); int res = memoized(coins, 0, amount, dp); return res == INT_MAX
        // ? -1 : res;

        // return tabulate(coins, amount);

        return spaceOptimized(coins, amount);
    }

    int spaceOptimized(vector<int>& coins, int amount) {
        int n = coins.size();

        vector<int> curr(amount + 1, 0);
        vector<int> next(amount + 1, INT_MAX);

        curr[0] = 0;

        for (int i = n - 1; i >= 0; i--) {
            for (int a = 1; a <= amount; a++) {
                int take = INT_MAX;
                if (coins[i] <= a) {
                    if (curr[a - coins[i]] != INT_MAX) {
                        take = 1 + curr[a - coins[i]];
                    }
                }

                int notTake = next[a];

                curr[a] = min(take, notTake);
            }
            next = curr;
        }

        return curr[amount] == INT_MAX ? -1 : curr[amount];
    }

    int tabulate(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 0));

        // BASE CASES
        for (int i = 0; i <= n; i++) {
            for (int a = 0; a <= amount; a++) {
                if (amount == 0)
                    dp[i][a] = 0;
                if (i == n)
                    dp[i][a] = INT_MAX;
            }
        }

        for (int i = n - 1; i >= 0; i--) {
            for (int a = 1; a <= amount; a++) {
                int take = INT_MAX;
                if (coins[i] <= a) {
                    if (dp[i][a - coins[i]] != INT_MAX) {
                        take = 1 + dp[i][a - coins[i]];
                    }
                }

                int notTake = dp[i + 1][a];

                dp[i][a] = min(take, notTake);
            }
        }

        return dp[0][amount] == INT_MAX ? -1 : dp[0][amount];
    }

    int memoized(vector<int>& coins, int i, int amount,
                 vector<vector<int>>& dp) {
        if (amount == 0)
            return 0;
        int n = coins.size();
        if (i >= n)
            return INT_MAX; // Impossible

        if (dp[i][amount] != -1)
            return dp[i][amount];

        int take = INT_MAX;
        if (coins[i] <= amount) {
            int remainingRes = memoized(coins, i, amount - coins[i], dp);
            if (remainingRes != INT_MAX) {
                take = 1 + remainingRes;
            }
        }

        int notTake = memoized(coins, i + 1, amount, dp);

        return dp[i][amount] = min(take, notTake);
    }

    int recursive(vector<int>& coins, int i, int amount) {
        if (amount == 0)
            return 0;
        int n = coins.size();
        if (i >= n)
            return INT_MAX; // Impossible

        int take = INT_MAX;
        if (coins[i] <= amount) {
            int remainingRes = recursive(coins, i, amount - coins[i]);
            if (remainingRes != INT_MAX) {
                take = 1 + remainingRes;
            }
        }

        int notTake = recursive(coins, i + 1, amount);

        return min(take, notTake);
    }
};