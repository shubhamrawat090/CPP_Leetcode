class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        ans.push_back(searchOccurrence(nums, target));
        ans.push_back(searchOccurrence(nums, target, false));
        return ans;
    }

    int searchOccurrence(vector<int>& nums, int target,
                         bool firstOccurrence = true) {
        int low = 0, high = nums.size() - 1;
        int ans = -1;

        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] == target) {
                ans = mid;
                if (firstOccurrence == true) {
                    // go left
                    high = mid - 1;
                } else {
                    // go right
                    low = mid + 1;
                }
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};