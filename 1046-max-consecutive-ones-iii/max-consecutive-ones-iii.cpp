class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int zeroes = 0;
        int n = nums.size();
        int left = 0;
        int maxLen = 0;
        for (int right = 0; right < n; right++) {
            if (nums[right] == 0)
                zeroes++;
            if (zeroes > k) {
                if (nums[left] == 0)
                    zeroes--;
                left++;
            }
            // if (zeroes <= k)
                maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};