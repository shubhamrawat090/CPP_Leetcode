class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int productOfAllExcept_0 = 1;
        int zeroCount = 0;
        for (int num : nums) {
            if (num == 0)
                zeroCount++;
            else
                productOfAllExcept_0 *= num;
        }

        int n = nums.size();
        vector<int> ans(n, 0);

        if (zeroCount > 1)
            return ans; // all will have zero

        for (int i = 0; i < n; i++) {
            if (zeroCount == 0) {
                // there are no zeroes
                ans[i] = productOfAllExcept_0 / nums[i];
            } else {
                // There is 1 zero
                if (nums[i] == 0) {
                    ans[i] = productOfAllExcept_0;
                } else {
                    ans[i] = 0;
                }
            }
        }

        return ans;
    }
};