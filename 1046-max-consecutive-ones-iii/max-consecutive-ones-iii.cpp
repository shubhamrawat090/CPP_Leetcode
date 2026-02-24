class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0, right = 0;
        int flips = 0, maxLen = 0;
        while (right < n) {
            if (nums[right] == 0) {
                flips++;
            }

            if (flips > k) {
                if (nums[left] == 0)
                    flips--;
                left++;
            }

            maxLen = max(right - left + 1, maxLen);

            right++;
        }
        return maxLen;
    }
};