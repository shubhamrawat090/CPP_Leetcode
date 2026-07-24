class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int maxSum = INT_MIN;
        for(int num: nums) {
            sum = max(sum + num, num);
            maxSum = max(sum, maxSum);
        }
        return maxSum;
    }
};