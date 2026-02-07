class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0, ans = INT_MIN;
        for(int num: nums) {
            sum += num;
            ans = max(ans, sum);
            if(sum < 0) {
                sum = 0;
            }
        }
        return ans;
    }
};