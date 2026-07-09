class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0, right = 0;
        int product = 1;
        long long count = 0;

        while (right < n) {
            product *= nums[right];
            // shrink left
            right++;
            while (left < n && product >= k) {
                product /= nums[left];
                left++;
            }
            count += (right - left);
        }

        return count;
    }
};