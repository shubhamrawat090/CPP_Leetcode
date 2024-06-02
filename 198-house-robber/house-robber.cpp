class Solution {
public:
    int rob(vector<int>& nums) {
        // int i=0, n=nums.size();
        // vector<int> dp(n, -1);
        // return helper(nums, i, n, dp);
        return tabulation(nums);
    }

    int helper(vector<int>& nums, int curr, int size, vector<int>& dp) {
        if(curr >= size) return 0;

        if(dp[curr] != -1) return dp[curr];

        // take curr -> can't take curr+1
        int takeCurr = nums[curr] + helper(nums, curr+2, size, dp);
        // not take curr ->can take cuur+1
        int notTakeCurr = helper(nums, curr+1, size, dp);

        return dp[curr] = max(takeCurr, notTakeCurr);
    }

    int tabulation(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];
        vector<int> dp(nums.size(), -1);
        dp[n-1] = nums[n-1];
        dp[n-2] = max(nums[n-1], nums[n-2]);
        for(int curr=n-3; curr>=0; curr--) {
            // take curr -> can't take curr+1
            int takeCurr = nums[curr] + dp[curr+2];
            // not take curr ->can take cuur+1
            int notTakeCurr = dp[curr+1];

            dp[curr] = max(takeCurr, notTakeCurr);
        }
        return dp[0];
    }
};