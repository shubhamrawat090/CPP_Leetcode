class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        ans.push_back(firstOccurrence(nums, target));
        ans.push_back(lastOccurrence(nums, target));
        return ans;
    }

    int firstOccurrence(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1, ans = -1;
        while(low <= high) {
            int mid = (low + high) / 2;
            if(nums[mid] == target) {
                ans = mid; // potential answer
                // First occurrence would be on left side 
                high = mid - 1;
            } else if(target > nums[mid]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }

    int lastOccurrence(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1, ans = -1;
        while(low <= high) {
            int mid = (low + high) / 2;
            if(nums[mid] == target) {
                ans = mid; // potential answer
                // Last occurrence would be on right side 
                low = mid + 1;
            } else if(target > nums[mid]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};