class Solution {
public:
    int search(vector<int>& nums, int target) {
        // Search for sorted site
        // Search if elem is inside sorted side
        int low = 0, high = nums.size() - 1;
        while(low <= high) {
            int mid = (low + high) / 2;
            if(nums[mid] == target) {
                return mid;
            }

            // nums[mid] can NEVER be equal to target

            // Is left side sorted? low -> mid
            if(nums[low] <= nums[mid]) {
                // Left side is sorted

                // Is target within sorted side - LEFT
                if(target >= nums[low] && target < nums[mid]) {
                    // Go left
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            } else {
                // Right side is sorted

                // Is target within sorted side - RIGHT
                if(target > nums[mid] && target <= nums[high]) {
                    // Go right
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }
        return -1;
    }
};