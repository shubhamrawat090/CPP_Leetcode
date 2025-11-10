class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int ans = 0;
        helper(nums, target, 0, ans);
        return ans;
    }

    void helper(vector<int>& nums, int target, int idx, int& ans) {
        if(idx == nums.size()) {
            if(target == 0) {
                ans++;
            }
            return;
        }

        // Add curr
        helper(nums, target - nums[idx], idx+1, ans);
        // Subtract curr
        helper(nums, target + nums[idx], idx+1, ans);
    }
};