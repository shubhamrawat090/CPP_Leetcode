class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = n - 1;
        while (low < high) {
            int mid = (low + high) / 2;
            if (nums[low] <= nums[mid]) {
                // check if minimum is at low
                if (nums[low] <= nums[high]) {
                    return nums[low];
                }
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return nums[high]; // or low
    }
};