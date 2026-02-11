class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        // int dp[100];
        if (n == 1)
            return nums[0];

        // dp[0] = nums[0];
        // dp[1] = max(nums[0], nums[1]);
        int prev2 = nums[0];
        int prev = max(nums[0], nums[1]);

        for (int i = 2; i < n; i++) {
            int notPick = prev;
            int pick = nums[i] + prev2;
            int ans = max(pick, notPick);
            prev2 = prev;
            prev = ans;
        }
        return prev;
    }
};