class Solution {
public:
    int jump(vector<int>& nums) {
        // return recursive(nums, 0);
        int n = nums.size();
        vector<int> dp(n, -1);
        return memoized(nums, 0, dp);
    }

    int memoized(vector<int>& nums, int start, vector<int>& dp) {
        int n = nums.size();
        if(start >= n-1) return 0;

        if(dp[start] != -1) return dp[start];

        int minJumps = n;
        for(int i=start+1; i<=start+nums[start]; i++) {
            int currJump = memoized(nums, i, dp);
            minJumps = min(1 + currJump, minJumps);
        }

        return dp[start] = minJumps;
    }

    int recursive(vector<int>& nums, int start) {
        int n = nums.size();
        if(start >= n-1) return 0;

        int minJumps = n;
        for(int i=start+1; i<=start+nums[start]; i++) {
            int currJump = recursive(nums, i);
            minJumps = min(1 + currJump, minJumps);
        }

        return minJumps;
    }
};