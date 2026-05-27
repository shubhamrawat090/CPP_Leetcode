class Solution {
public:
    bool canJump(vector<int>& nums) { 
        // return recursive(nums, 0); 
        int n = nums.size();
        vector<int> dp(n+1, -1);
        return memoized(nums, 0, dp);
    }

    bool memoized(vector<int>& nums, int start, vector<int>& dp) {
        int n = nums.size();
        if (start >= n - 1)
            return true;
        
        if(dp[start] != -1) return dp[start] == 1 ? true : false;

        for (int idx = start + 1; idx <= start + nums[start]; idx++) {
            if (memoized(nums, idx, dp))
                return dp[start] = true;
        }

        return dp[start] = false;
    }

    bool recursive(vector<int>& nums, int start) {
        int n = nums.size();
        if (start >= n - 1)
            return true;

        for (int idx = start + 1; idx <= start + nums[start]; idx++) {
            if (recursive(nums, idx))
                return true;
        }

        return false;
    }
};