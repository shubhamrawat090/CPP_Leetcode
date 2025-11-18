class Solution {
public:
    void sortColors(vector<int>& nums) {
        // low -> 0s
        // mid -> 1s
        // high -> 2s
        int low = 0, mid = 0, high = nums.size() - 1;
        while(mid <= high) {
            // mid can be 0, 1, 2
            if(nums[mid] == 0) {
                swap(nums[mid], nums[low]);
                mid++, low++;
            } else if(nums[mid] == 1) {
                mid++;
            } else {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};