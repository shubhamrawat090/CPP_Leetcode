class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int idx = -1;
        int n = nums.size();
        for(int i=n-2; i>=0; i--) {
            if(nums[i] < nums[i+1]) {
                idx = i;
                break;
            }
        }

        if(idx == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        for(int i=n-1; i>=idx; i--) {
            if(nums[i] > nums[idx]) {
                swap(nums[i], nums[idx]);
                break;
            }
        }

        // reverse(nums, idx+1, n-1);
        int left = idx+1, right = n-1;
        while(left < right) {
            swap(nums[left], nums[right]);
            left++, right--;
        }
    }
};