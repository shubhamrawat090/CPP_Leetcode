class Solution {
public:
    int search(vector<int>& nums, int target) {
        // low, mid, high: leftRange = low..mid, rightRange = mid...high
        // if: low <= mid then leftRange is sorted
        // else: rightRange is sorted
        // After getting which range is sorted CHECK IF target IS INSIDE SORTED RANGE
        // EXAMPLE:
        // if leftRange sorted AND target is inside leftRange then high = mid-1; // GO LEFT
        // else: low = mid+1; // GO RIGHT
        // AND VICE VERSA
        int low = 0, high = nums.size()-1;
        while(low <= high) {
            int mid = (low + high) / 2;
            if(nums[mid] == target) return mid;
            
            // is left range sorted?
            if(nums[low] <= nums[mid]) {// LEFT RANGE SORTED
                // is target inside left range?
                if(target >= nums[low] && target <= nums[mid]) {
                    high = mid-1; // go left
                } else {
                    low = mid+1; // go right
                }
            } else {// RIGHT RANGE SORTED
                // is target inside right range?
                if(target >= nums[mid] && target <= nums[high]) {
                    low = mid+1; // go right
                } else {
                    high = mid-1; // go left
                }
            }
        }
        return -1;
    }
};