class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        // return recursive(nums, target, 0, 0);

        int totalSum = 0;
        for(int val: nums) {
            totalSum += val;
        }
        vector<vector<int>> dp(nums.size() + 1, vector<int>(2*totalSum + 1, -1)); // can go -totalSum to +totalSum. Hence, we need to shift indices to sum + totalSum
        return memoized(nums, target, 0, 0, dp, totalSum);
    }

    int memoized(vector<int>& nums, int& target, int sum, int i, vector<vector<int>>& dp, int& totalSum) {
        int n = nums.size();
        if(i == n) {
            return sum == target ? 1 : 0;
        }

        if(dp[i][sum + totalSum] != -1) {
            return dp[i][sum + totalSum];
        }

        // pick - make curr num minus(-), notPick - keep curr num plus(+)
        int pick = memoized(nums, target, sum - nums[i], i+1, dp, totalSum);
        int notPick = memoized(nums, target, sum + nums[i], i+1, dp, totalSum);
        return dp[i][sum + totalSum] = pick + notPick;
    }

    int recursive(vector<int>& nums, int& target, int sum, int i) {
        int n = nums.size();
        if(i == n) {
            return sum == target ? 1 : 0;
        }

        // pick - make curr num minus(-), notPick - keep curr num plus(+)
        int pick = recursive(nums, target, sum - nums[i], i+1);
        int notPick = recursive(nums, target, sum + nums[i], i+1);
        return pick + notPick;
    }
};