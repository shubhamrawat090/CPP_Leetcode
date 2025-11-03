class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int ans = 0;
        for(int i=0; i<nums.size(); i++) {
            int leftElem = i == 0 ? INT_MIN : nums[i - 1];
            int rightElem = i == nums.size() - 1 ? INT_MIN : nums[i + 1];
            if(nums[i] > leftElem && nums[i] > rightElem) {
                ans = i;
                break;
            }
        }
        return ans;
    }
};