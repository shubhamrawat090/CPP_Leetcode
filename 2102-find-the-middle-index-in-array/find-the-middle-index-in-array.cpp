class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int n = nums.size();
        int leftSum = 0, rightSum = 0, totalSum = 0;
        for (int num : nums) {
            totalSum += num;
        }
        rightSum = totalSum;
        for (int i = 0; i < n; i++) {
            if (i != 0) {
                leftSum += nums[i - 1];
            }

            rightSum -= nums[i];

            if (leftSum == rightSum) {
                return i;
            }
        }
        return -1;
    }
};