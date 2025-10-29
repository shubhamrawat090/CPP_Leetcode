class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0, ans = INT_MIN;
        for(int num: nums) {
            sum += num;
            ans = max(ans, sum);
            sum = max(0, sum);
        }
        return ans;
    }
};