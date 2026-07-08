class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n-1;
        int pos = n-1;
        vector<int> ans(n);
        while(left <= right) {
            int leftVal = abs(nums[left]);
            int rightVal = abs(nums[right]);
            if(leftVal > rightVal) {
                ans[pos] = leftVal * leftVal;
                left++;
            } else {
                ans[pos] = rightVal * rightVal;
                right--;
            }
            pos--;
        }
        return ans;
    }
};