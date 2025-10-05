class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int ans = -1;

        int totalSum = 0;
        for(int i=0; i<nums.size(); i++) {
            totalSum += nums[i];
        }

        int leftSum = 0, rightSum = totalSum;
        for(int i=0; i<nums.size(); i++) {
            rightSum -= nums[i];

            if(leftSum == rightSum) {
                ans = i;
                break;
            }

            leftSum += nums[i];
        }

        return ans;
    }
};