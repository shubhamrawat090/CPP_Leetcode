class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxSum = INT_MIN, sum = 0;
        for(int st=0; st<n; st++) {
            sum += nums[st];
            maxSum = max(sum, maxSum);
            if(sum < 0) {
                sum = 0;
            }
        }
        return maxSum;
    }
};