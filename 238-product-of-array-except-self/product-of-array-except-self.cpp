class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int zeroFreq = 0;
        int productExceptZero = 1;
        for(int num: nums) {
            if(num == 0) zeroFreq++;
            else productExceptZero *= num;
        }

        int n = nums.size();
        vector<int> ans(n, 0);
        if(zeroFreq > 1) return ans; // all will be zeroes

        for(int i=0; i<n; i++) {
            if(nums[i] == 0) {
                ans[i] = productExceptZero;
            } else if(zeroFreq == 0) {
                ans[i] = productExceptZero / nums[i];
            } else if(zeroFreq == 1) {
                ans[i] = 0;
            }
        }

        return ans;
    }
};