class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProd = INT_MIN, prod = 1, n = nums.size();
        // left -> right
        for(int i=0; i<n; i++) {
            prod *= nums[i];
            maxProd = max(maxProd, prod);
            if(prod == 0) {
                prod = 1;
            }
        }

        // Reset the product FOR A FRESH TRAVERSAL
        prod = 1;

        // right -> left
        for(int i=n-1; i>=0; i--) {
            prod *= nums[i];
            maxProd = max(maxProd, prod);
            if(prod == 0) {
                prod = 1;
            }
        }

        return maxProd;
    }
};