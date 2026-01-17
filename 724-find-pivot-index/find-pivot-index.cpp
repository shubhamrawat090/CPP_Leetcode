class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int leftSum = 0, rightSum = 0;
        for(int num: nums) {
            rightSum += num;
        }

        for(int i=0; i<nums.size(); i++) {
            int num = nums[i];
            rightSum -= num;
            if(leftSum == rightSum) return i;
            leftSum += num;
        }

        return -1;
    }
};