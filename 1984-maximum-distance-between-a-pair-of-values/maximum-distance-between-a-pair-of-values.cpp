class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int maxDist = 0;
        int left = 0;
        for(int i=0; i<nums1.size(); i++) {
            left = i;
            int right = nums2.size()-1;
            if(left <= right && nums1[i] <= nums2[left]) {
                left = binarySearch(nums2, left, right, nums1[i]);
                maxDist = max(maxDist, left - i);
            }
        }
        return maxDist;
    }

    int binarySearch(vector<int>& nums, int left, int right, int target) {
        int ans = -1;
        while(left <= right) {
            int mid = (left + right) / 2;
            if(nums[mid] == target) {
                ans = mid;
                left = mid+1;
            } else if(nums[mid] < target) {
                right = mid-1;
            } else {
                left = mid+1;
            }
        }
        return ans == -1 ? right : ans;
    }
};