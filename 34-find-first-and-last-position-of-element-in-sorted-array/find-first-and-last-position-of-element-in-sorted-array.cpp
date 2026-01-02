class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        int firstPos = findFirstPos(nums, target);
        ans.push_back(firstPos);
        if(firstPos != -1) {
            int lastPos = findLastPos(nums, target);
            ans.push_back(lastPos);
        } else {
            ans.push_back(-1);
        }
        return ans;
    }

    int findFirstPos(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n - 1, ans = -1;
        while(low <= high) {
            int mid = (low + high) / 2;
            if(nums[mid] == target) {
                ans = mid;
                high = mid - 1;
            } else if(nums[mid] > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }

    int findLastPos(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n - 1, ans = -1;
        while(low <= high) {
            int mid = (low + high) / 2;
            if(nums[mid] == target) {
                ans = mid;
                low = mid + 1;
            } else if(nums[mid] > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};