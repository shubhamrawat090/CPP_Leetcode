class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int totalSum = 0;
        for(int num: nums) {
            totalSum += num;
        }

        int leftSum = 0, rightSum = totalSum, ans = -1;
        for(int i=0; i<nums.size(); i++) {
            int num = nums[i];
            rightSum -= num;
            if(leftSum == rightSum) {
                ans = i;
                break;
            }
            leftSum += num;
        }

        return ans;
    }
};