class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;

        // FACT: Minimum ALWAYS lies in unsorted side

        while (low < high) {
            int mid = (low + high) / 2;

            // Easier to check right side
            if (nums[mid] > nums[high]) {
                // Right side is sorted - Go right
                low = mid + 1;
            } else {
                // Left side is sorted - Go left
                high = mid;
            }
        }

        return nums[low]; // nums[high]
    }
};