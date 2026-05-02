class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0, ans = INT_MIN;
        for(int num: nums) {
            sum += num;
            ans = max(sum, ans);
            if(sum < 0) {
                sum = 0;
            }
        }
        return ans;
    }
};