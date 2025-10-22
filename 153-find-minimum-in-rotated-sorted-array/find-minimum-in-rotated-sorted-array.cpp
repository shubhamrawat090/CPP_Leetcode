class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        while (low < high) {
            int mid = (low + high) / 2;
            // NOTE: Check the right side always -> mid - high
            if (nums[mid] > nums[high]) {
                // unsorted part -> ans is here only
                low = mid + 1;
            } else {
                // sorted part -> answer cannot be here
                high = mid;
            }
        }
        return nums[high]; // or low
    }
};