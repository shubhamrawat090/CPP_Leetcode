class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // int res = recursive(coins, 0, amount);
        vector<vector<int>> dp(coins.size() + 1, vector<int>(amount + 1, -1));
        int res = memoized(coins, 0, amount, dp);
        return res == INT_MAX ? -1 : res;
    }

    int memoized(vector<int>& coins, int i, int amount, vector<vector<int>>& dp) {
        if (amount == 0)
            return 0;
        int n = coins.size();
        if (i >= n)
            return INT_MAX; // Impossible

        if(dp[i][amount] != -1) return dp[i][amount];

        int take = INT_MAX;
        if (coins[i] <= amount) {
            int remainingRes = memoized(coins, i, amount - coins[i], dp);
            if (remainingRes != INT_MAX) {
                take = 1 + remainingRes;
            }
        } 
        

        int notTake = memoized(coins, i+1, amount, dp);
    

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
        

        int notTake = recursive(coins, i+1, amount);
    

        return min(take, notTake);
    }
};