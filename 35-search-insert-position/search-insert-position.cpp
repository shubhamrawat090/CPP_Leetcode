class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // Just bigger and target IF TARGET IS NOT PRESENT -> return low
        int low = 0, high = nums.size() - 1;
        while(low <= high) {
            int mid = (low + high) / 2;
            if(nums[mid] == target) {
                return mid;
            } else if(nums[mid] < target) {
                // go right
                low = mid + 1;
            } else {
                // go left
                high = mid - 1;
            }
        }
        return low;
    }
};