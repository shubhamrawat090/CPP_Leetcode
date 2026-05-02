class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0; // 0 house
        if(n == 1) return nums[0]; // 1 house
        vector<int> dp(n, 0); // dp[i] = maximum money till nums[i] house
        dp[0] = nums[0]; // till 0th house there is only 1 house
        dp[1] = max(nums[0], nums[1]); // either take the 0th or 1st house

        for(int i=2; i<n; i++) {
            int take = nums[i] + dp[i-2]; // if I take ith house then I have to ignore (i-1)th
            int notTake = dp[i-1];
            dp[i] = max(take, notTake);
        }

        return dp[n-1]; // Till nums[n-1] house i.e. the last house
    }
};