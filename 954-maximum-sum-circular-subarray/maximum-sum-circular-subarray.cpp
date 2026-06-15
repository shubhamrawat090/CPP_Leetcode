class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        // ____S1___|___S2__|___S3___
        // Circular sum = S2 + S3
        // If circular sum is MAXIMUM then S2 is MINIMUM. 
        // Because if we decrease S2 then circular sum increase ==> WHICH IS IMPOSSIBLE AS circular sum is max

        // We need these
        // 1. Total Sum
        // 2. Min Sum Subarray (Using Kadane)
        // 3. Circular Sum = Total Sum - Min Sum SubArray
        // 4. Max Sum Subarray (Using Kadane)

        // If MaxSum >= 0 return ==> max(maxSum, circular_sum)
        // Else return maxSum

        // BECAUSE, for the case [-1, -1, -1]
        // totalSum = -3, minSum = -3, circular_sum = -3-(-3) = 0, maxSum = -1
        // Here circular_sum(0) > maxSum (-1) BUT THIS IS NOT POSSIBLE
        int totalSum = 0;
        for(int num: nums) {
            totalSum += num;
        }
        int minSum = getMinSubArrSum(nums);
        int circularSum = totalSum - minSum;
        int maxSum = getMaxSubArrSum(nums);
        return maxSum < 0 ? maxSum : max(maxSum, circularSum);
    }

    int getMaxSubArrSum(vector<int>& nums) {
        int n = nums.size();
        int sum = nums[0];
        int maxSum = nums[0];
        for(int i=1; i<n; i++) {
            sum = max(sum + nums[i], nums[i]);
            maxSum = max(sum, maxSum);
        }
        return maxSum;
    }

    int getMinSubArrSum(vector<int>& nums) {
        int n = nums.size();
        int sum = nums[0];
        int minSum = nums[0];
        for(int i=1; i<n; i++) {
            sum = min(sum + nums[i], nums[i]);
            minSum = min(sum, minSum);
        }
        return minSum;
    }
};