class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        vector<int> ans(n, 1);

        int leftProduct = 1;
        int prefixLeft[n];
        for (int i = 0; i < n; i++) {
            leftProduct *= nums[i];
            prefixLeft[i] = leftProduct;
        }

        int rightProduct = 1;
        int prefixRight[n];
        for (int i = n - 1; i >= 0; i--) {
            rightProduct *= nums[i];
            prefixRight[i] = rightProduct;
        }

        for (int i = 0; i < n; i++) {
            int lP = (i == 0) ? 1 : prefixLeft[i - 1];
            int rP = (i == n - 1) ? 1 : prefixRight[i + 1];
            ans[i] = lP * rP;
        }

        return ans;
    }
};