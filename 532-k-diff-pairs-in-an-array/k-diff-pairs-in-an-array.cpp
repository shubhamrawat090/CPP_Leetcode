class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int left = 0, right = 1;
        int count = 0;
        while(right < n) {
            if(left == right) {
                right++;
                continue;
            }
            int diff = nums[right] - nums[left];
            if(diff == k) {
                count++;
                left++, right++;

                // Skip all copies of left and right as we need unique pairs only
                while(left < n && nums[left] == nums[left-1]) left++;
                while(right < n && nums[right] == nums[right-1]) right++;
            } else if(diff > k) {
                left++;
            } else {
                right++;
            }
        }
        return count;
    }
};