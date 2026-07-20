class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        return oneStepKadane(nums);
        // return twoStepKadane(nums);
    }

    int oneStepKadane(vector<int>& nums) {
        int n = nums.size();
        int currSum_max = nums[0];
        int currSum_min = nums[0];
        int maxSum = nums[0];
        int minSum = nums[0];
        for(int i=1; i<n; i++) {
            currSum_max = max(nums[i], currSum_max + nums[i]);
            maxSum = max(currSum_max, maxSum);

            currSum_min = min(nums[i], currSum_min + nums[i]);
            minSum = min(currSum_min, minSum);
        }
        return max(maxSum, abs(minSum));
    }

    int twoStepKadane(vector<int>& nums) {
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