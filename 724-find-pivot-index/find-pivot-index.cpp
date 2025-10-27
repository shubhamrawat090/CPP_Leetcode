class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int total = 0;
        for(int num: nums) {
            total += num;
        }
        int leftSum = 0, rightSum = total;
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