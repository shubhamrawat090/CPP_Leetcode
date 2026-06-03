class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<long long>> dp(n+1, vector<long long>(amount+1, 0));

        dp[0][0] = 0;
        for(int j=1; j<=amount; j++) {
            // When 0 coins => amount = 0 takes 0 coins. Other amounts are IMPOSSIBLE TO MAKE
            dp[0][j] = INT_MAX;
        }

        for(int i=1; i<=n; i++) {
            for(int j=1; j<=amount; j++) {
                long long take = INT_MAX;
                if(j >= coins[i-1]) {
                    take = 1 + dp[i][j-coins[i-1]];
                }

                long long notTake = dp[i-1][j];

                dp[i][j] = min(take, notTake); 
            }
        }
        return dp[n][amount] == INT_MAX ? -1 : dp[n][amount];
    }
};