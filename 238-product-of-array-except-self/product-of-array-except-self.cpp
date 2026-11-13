class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        // get totalProduct: without zeroes
        // count no. of zeroes
        // case 1 - No zeroes
        // Solve normally, ans[i] = totalProduct / nums[i]
        // case 2 - 1 zero
        // Everything except, the zero index is zero
        // at nums[i] == 0, ans[i] = totalProduct
        // case 3 - >1 zeroes
        // everything is zero in the answer
        // ans[i] = 0, always

        int totalProduct = 1;
        int zeroCount = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                zeroCount++;
            } else {
                totalProduct *= nums[i];
            }
        }

        vector<int> ans(n, 0);
        if (zeroCount == 0) {
            for (int i = 0; i < n; i++) {
                ans[i] = totalProduct / nums[i];
            }
        } else if (zeroCount == 1) {
            for (int i = 0; i < n; i++) {
                if (nums[i] == 0) {
                    ans[i] = totalProduct;
                }
            }
        } else {
            // Do nothing, everything is ZERO in ans
        }

        return ans;
    }
};