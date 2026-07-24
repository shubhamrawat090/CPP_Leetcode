class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prefix = 1, suffix = 1;
        int maxProduct = INT_MIN;
        int n = nums.size();
        // Observation: all +ve ==> Ans = prod ALL
        // Observation: even -ves, all +ve ==> Ans = prod ALL
        // Observation: odd -ves, all +ve
        // num: 1   -2   4 3  -4  5 6   -2   3
        // for -2 ans is either left side all or right side all. Similarly for all other negatives
        // (1) -2 ( 4 3 -4 5 6 -2 3)
        // (1 -2 4 3) -4 (5 6 -2 3)
        // (1 -2 4 3 -4 5 6) -2 (3)

        // Observation: Has zeroes
        // (1 -3 2 23) 0 (-1 2 4) 0 (1 2 4)
        // break into different subarrays and solve
        // At every zero we start with 1 
        for(int i=0; i<n; i++) {
            if(prefix == 0) prefix = 1;
            if(suffix == 0) suffix = 1;

            prefix *= nums[i];
            suffix *= nums[n-i-1];

            maxProduct = max(maxProduct, max(prefix, suffix));
        } 
        return maxProduct;
    }
};