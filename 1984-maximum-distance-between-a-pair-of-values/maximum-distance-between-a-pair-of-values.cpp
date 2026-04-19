class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        // return useBinarySearch(nums1, nums2);
        return use2Pointers(nums1, nums2);
    }

    int use2Pointers(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        int i = 0;
        int j = 0;
        int ans = 0;

        while(i < n && j < m)
        {
            if(nums1[i] <= nums2[j])
            {
                ans = max(ans, j-i);
                j++;     // try to increase distance
            }
            else
            {
                i++;     // make nums1 smaller
            }
        }

        return ans;
    }

    int useBinarySearch(vector<int>& nums1, vector<int>& nums2) {
        int maxDist = 0;
        int left = 0;

        // BIG HINT
        // If for some i, the farthest valid j is 7
        // then for i+1 (smaller value), the farthest valid j cannot move left.

        // It will either:

        // stay same
        // move right

        // So j pointer never needs to reset back to i each time.
        for (int i = 0; i < nums1.size(); i++) {
            left = i;
            int right = nums2.size() - 1;
            if (left <= right && nums1[i] <= nums2[left]) {
                left = binarySearch(nums2, left, right, nums1[i]);
                maxDist = max(maxDist, left - i);
            }
        }
        return maxDist;
    }

    int binarySearch(vector<int>& nums, int left, int right, int target) {
        int ans = -1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) {
                ans = mid;
                left = mid + 1;
            } else if (nums[mid] < target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans == -1 ? right : ans;
    }
};