class Solution {
public:
    int findMin(vector<int>& nums) {
        // 1 part is always sorted
        // Minimum always lies in the unsorted part

        // WE WANT RIGHT PART TO BE SORTED - mid -> high
        int low = 0, high = nums.size() - 1;
        while(low < high) {
            int mid = (low + high) / 2;
            // We check if the part is unsorted
            if(nums[mid] > nums[high]) {
                // right part is unsorted
                low = mid + 1; // we can skip mid here because nums[mid] is greater than another value here. Hence, cannot be min val
            } else {
                high = mid;
            }
        }
        return nums[high]; // nums[low] as both will point to same at the end
    }
};