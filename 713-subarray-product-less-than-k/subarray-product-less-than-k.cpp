class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0;
        // For a window if left --> right subarray product < k
        // then left+1 ---> right ALSO < k
        // then left+2 ---> right ALSO < k
        // Therefore, count of subarrays = no. of elements b/w [left, right] = right-left+1
        long long count = 0;
        int product = 1;
        for(int right=0; right<n; right++) {
            product *= nums[right];
            while(left <= right && product >= k) {
                product /= nums[left];
                left++;
            }
            count += (right-left+1);
        }
        return count;
    }
};