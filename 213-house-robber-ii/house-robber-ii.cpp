class Solution {
public:
    int rob(vector<int>& nums) {
        // not take last house: nums[0....N-2], ans = dp1[n-2]
        // take last house: nums[1....N-1], ans = dp2[n-1]
        // final answer = max(dp2[n-1], dp1[n-2])
        int n = nums.size();

        if(n == 0) return 0;
        if(n == 1) return nums[0];

        vector<int> dp1(n);
        dp1[0] = nums[0];
        dp1[1] = max(nums[0], nums[1]);
        for(int i=2; i<n-1; i++) {
            int take = nums[i] + dp1[i-2];
            int notTake = dp1[i-1];
            dp1[i] = max(take, notTake);
        }

        vector<int> dp2(n);
        dp2[0] = 0;
        dp2[1] = nums[1];
        for(int i=2; i<n; i++) {
            int take = nums[i] + dp2[i-2];
            int notTake = dp2[i-1];
            dp2[i] = max(take, notTake);
        }

        return max(dp1[n-2], dp2[n-1]);
    }
};