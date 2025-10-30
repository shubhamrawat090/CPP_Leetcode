class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currSum = 0, maxSum = INT_MIN;
        int currLeft = 0, maxLeft = 0, maxRight = 0;

        for (int i = 0; i < nums.size(); i++) {
            currSum += nums[i];

            // Update max if we found a better sum
            if (currSum > maxSum) {
                maxSum = currSum;
                maxLeft = currLeft;
                maxRight = i;
            }

            // Reset if current sum goes below 0
            if (currSum < 0) {
                currSum = 0;
                currLeft = i + 1;
            }
        }

        cout << "Max subarray indices: (" << maxLeft << ", " << maxRight << ")\n";
        return maxSum;
    }
};
