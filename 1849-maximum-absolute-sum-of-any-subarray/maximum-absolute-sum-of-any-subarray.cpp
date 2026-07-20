class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxSum = getMaxSum(nums);
        int minSum = getMinSum(nums);
        return max(maxSum, abs(minSum));
    }

    int getMaxSum(vector<int>& nums) {
        int sum = nums[0];
        int maxSum = nums[0];
        int n = nums.size();
        for(int i=1; i<n; i++) {
            sum = max(nums[i], sum + nums[i]);
            maxSum = max(maxSum, sum);
        }
        return maxSum;
    }

    int getMinSum(vector<int>& nums) {
        int sum = nums[0];
        int minSum = nums[0];
        int n = nums.size();
        for(int i=1; i<n; i++) {
            sum = min(nums[i], sum + nums[i]);
            minSum = min(minSum, sum);
        }
        return minSum;
    }
};