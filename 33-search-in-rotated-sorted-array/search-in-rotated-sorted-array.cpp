class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        while(low <= high) {
            int mid = (low + high) / 2;
            if(nums[mid] == target) {
                return mid;
            }

            // NOTE: nums[mid] cannot be equal to target as we covered it in the first If statement

            // Is the left range (low -> mid) a sorted one like 1,3,4,5
            if(nums[low] <= nums[mid]) {
                // Can target be between this range nums[low] -> nums[mid]
                if(target >= nums[low] && target < nums[mid]) { 
                    // We move on the search on the left range only
                    high = mid - 1;
                } else {
                    // we move on to the right range
                    low = mid + 1;
                }

            }
            // Left range (low -> mid) is not a sorted one like 5,6,1,2,3
            else {
                // WE KNOW THAT The right range is sorted here (mid -> high)
                // Can the target be in the right range(nums[mid], nums[high])
                if(target > nums[mid] && target <= nums[high]) {
                    // We keep searching in the right range
                    low = mid + 1;
                } else {
                    // We move to the left range
                    high = mid - 1;
                }
            }
        }
        return -1;
    }
};