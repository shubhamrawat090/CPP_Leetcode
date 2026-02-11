class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        if(n == 0) return 0;
        if(n == 1) return cost[0];
        // vector<int> dp(n, 0);
        // dp[0] = cost[0];
        // dp[1] = cost[1];
        int prev2 = cost[0], prev1 = cost[1];
        for(int i=2; i<n; i++) {
            int ans = cost[i] + min(prev1, prev2);
            prev2 = prev1;
            prev1 = ans;
        }
        return min(prev1, prev2);
    }
};