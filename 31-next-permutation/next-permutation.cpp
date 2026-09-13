class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int idx = -1;
        int n = nums.size();
        // 1. Find DIP point
        for(int i=n-2; i>=0; i--) {
            if(nums[i] < nums[i+1]) {
                idx = i;
                break;
            }
        }

        // Edge case: No DIP found --> LAST lexicographical configuration
        if(idx == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        // 2. Find JUST GREATER to nums[idx]
        for(int i=n-1; i>=idx; i--) {
            if(nums[i] > nums[idx]) {
                swap(nums[i], nums[idx]);
                break;
            }
        }

        // 3. reverse(nums, idx+1, n-1);
        int left = idx+1, right = n-1;
        while(left < right) {
            swap(nums[left], nums[right]);
            left++, right--;
        }
    }
};