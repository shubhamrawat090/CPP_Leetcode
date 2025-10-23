class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int totalSum = 0;
        for(int num: nums) {
            totalSum += num;
        }

        int leftSum = 0, rightSum = totalSum;
        for(int i=0; i<nums.size(); i++) {
            rightSum -= nums[i];
            if(leftSum == rightSum) {
                return i;
            }
            leftSum += nums[i];
        }

        return -1;
    }
};