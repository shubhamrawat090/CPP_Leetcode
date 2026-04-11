class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int firstPos = getFirstPos(nums, target);
        if(firstPos == -1) {
            return {-1, -1};
        }
        int lastPos = getLastPos(nums, target);
        return {firstPos, lastPos};
    }

private:
    int getFirstPos(vector<int>& nums, int target) {
        int ans = -1, n = nums.size();
        int low = 0, high = n-1;
        while(low <= high) {
            int mid = (low + high) / 2;
            if(target == nums[mid]) {
                ans = mid;
                high = mid-1;
            } else if(target > nums[mid]) {
                low = mid+1;
            } else {
                high = mid-1;
            }
        }
        return ans;
    }

    int getLastPos(vector<int>& nums, int target) {
        int ans = -1, n = nums.size();
        int low = 0, high = n-1;
        while(low <= high) {
            int mid = (low + high) / 2;
            if(target == nums[mid]) {
                ans = mid;
                low = mid+1;
            } else if(target > nums[mid]) {
                low = mid+1;
            } else {
                high = mid-1;
            }
        }
        return ans;
    }
};