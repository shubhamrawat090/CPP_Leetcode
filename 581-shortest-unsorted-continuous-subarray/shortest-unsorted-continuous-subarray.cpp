class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int minVal = INT_MAX;
        int maxVal = INT_MIN;

        // Find the minimum and maximum misplaced values
        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[i - 1]) {
                minVal = min(minVal, nums[i]);
                maxVal = max(maxVal, nums[i - 1]);
            }
        }

        // Array is already sorted
        if (minVal == INT_MAX)
            return 0;

        // Find the correct left boundary
        int left = 0;
        while (left < n && nums[left] <= minVal)
            left++;

        // Find the correct right boundary
        int right = n - 1;
        while (right >= 0 && nums[right] >= maxVal)
            right--;

        return right - left + 1;
    }
};