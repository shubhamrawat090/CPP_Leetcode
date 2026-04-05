class Solution {
public:
    int change(int amount, vector<int>& coins) {
        // return recursive(amount, coins, 0);
        // return tabulation(amount, coins); // Gives integer overflow when we do dp[i][a] = take + skip
        return spaceOptimised(amount, coins); 
    }

    int spaceOptimised(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<unsigned int> dp(amount+1, 0);

        // base case - 1 way with amount = 0
        dp[0] = 1;

        for(int coin: coins) {
            for(int a = coin; a<=amount; a++) {
                dp[a] += dp[a-coin];
            }
        }

        return dp[amount];
    }

    int tabulation(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<long long>> dp(n+1, vector<long long>(amount + 1, 0LL));

        // base case - 1 way with amount = 0
        for(int i=0; i<=n; i++) {
            dp[i][0] = 1;
        }

        for(int i=n-1; i>=0; i--) {
            for(int a = 1; a<=amount; a++) {
                long long take = 0;
                if(a >= coins[i]) {
                    take = dp[i][a-coins[i]];
                }
                long long skip = dp[i+1][a];
                dp[i][a] = take + skip;
            }
        }

        return dp[0][amount];
    }

    int recursive(int amount, vector<int>& coins, int i) {
        if(amount == 0) return 1; // 1 way - no coins
        if(i >= coins.size()) return 0; // no way - no coins available

        int totalWays = 0;
        // take current coin
        if(amount >= coins[i]) {
            totalWays += recursive(amount - coins[i], coins, i); // pass i because we can take same coin again
        }

        // not take current coin
        totalWays += recursive(amount, coins, i + 1); // pass i + 1 because we can take NEXT coin
        
        return totalWays;
    }
};