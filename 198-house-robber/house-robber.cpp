class Solution {
public:
    int rob(vector<int>& nums) {
        int i=0, n=nums.size();
        vector<int> dp(n, -1);
        return helper(nums, i, n, dp);
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
};