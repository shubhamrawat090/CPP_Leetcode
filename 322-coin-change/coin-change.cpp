class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        // int ans = recursive(coins, amount, n);
        // vector<vector<int>> dp(n + 1, vector<int>(amount + 1, -1));
        // int ans = memoized(coins, amount, n, dp);
        // return ans == INT_MAX ? -1 : ans;
        // return tabulate(coins, amount, n);
        return spaceOptimize(coins, amount, n);
    }

    int spaceOptimize(vector<int>& coins, int amount, int n) {
        vector<int> prev(amount + 1, 0);

        if (n >= 0) {
            // n = 1 coin row, from amount: 1 -> amount+1
            for (int j = 1; j < amount + 1; j++) {
                prev[j] = j % coins[0] == 0 ? j / coins[0] : INT_MAX;
            }
        }

        for (int i = 2; i < n + 1; i++) {
            vector<int> curr(amount+1, INT_MAX);
            curr[0] = 0;
            for (int j = 1; j < amount + 1; j++) {
                if (j >= coins[i - 1]) {
                    int pickCall = curr[j - coins[i - 1]];
                    int pick = pickCall == INT_MAX ? INT_MAX : 1 + pickCall;
                    int notPick = prev[j];
                    curr[j] = min(pick, notPick);
                } else {
                    int notPick = prev[j];
                    curr[j] = notPick;
                }
            }
            prev = curr;
        }

        return prev[amount] == INT_MAX ? -1 : prev[amount];
    }

    int tabulate(vector<int>& coins, int amount, int n) {
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 0));

        if (n >= 0) {
            // n = 1 coin row, from amount: 1 -> amount+1
            for (int j = 1; j < amount + 1; j++) {
                dp[1][j] = j % coins[0] == 0 ? j / coins[0] : INT_MAX;
            }
        }

        for (int i = 2; i < n + 1; i++) {
            for (int j = 1; j < amount + 1; j++) {
                if (j >= coins[i - 1]) {
                    int pickCall = dp[i][j - coins[i - 1]];
                    int pick = pickCall == INT_MAX ? INT_MAX : 1 + pickCall;
                    int notPick = dp[i - 1][j];
                    dp[i][j] = min(pick, notPick);
                } else {
                    int notPick = dp[i - 1][j];
                    dp[i][j] = notPick;
                }
            }
        }

        return dp[n][amount] == INT_MAX ? -1 : dp[n][amount];
    }

    int memoized(vector<int>& coins, int amount, int n,
                 vector<vector<int>>& dp) {
        if (amount == 0) {
            return 0; // 0 amounts can be made up by using 0 coins
        }

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