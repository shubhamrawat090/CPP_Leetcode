class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int pos = n-1;
        int left = 0;
        int right = n-1;
        vector<int> ans(n);
        while(pos >= 0) {
            int leftAbs = abs(nums[left]);
            int rightAbs = abs(nums[right]);
            if(leftAbs > rightAbs) {
                ans[pos--] = nums[left] * nums[left];
                left++;
            } else {
                ans[pos--] = nums[right] * nums[right];
                right--;
            }
        }
        return ans;
    }
};