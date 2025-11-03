class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        ans.push_back(firstPos(nums, target));
        ans.push_back(lastPos(nums, target));
        return ans;
    }

    int firstPos(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1, ans = -1;
        while(low <= high) {
            int mid = (low + high) / 2;
            if(nums[mid] == target) {
                // Potential ans
                ans = mid;
                // Go left - first pos
                high = mid - 1;
            } else if(nums[mid] > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }

    int lastPos(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1, ans = -1;
        while(low <= high) {
            int mid = (low + high) / 2;
            if(nums[mid] == target) {
                // Potential ans
                ans = mid;
                // Go right - last pos
                low = mid + 1;
            } else if(nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};