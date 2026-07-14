class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int oneFreq = 0, zeroFreq = 0;
        int n = nums.size();
        int maxLen = 0;
        int left = 0;
        for (int right = 0; right < n; right++) {
            if (nums[right] == 0)
                zeroFreq++;

            int flips = zeroFreq;

            if (flips > k) {
                if (nums[left] == 0)
                    zeroFreq--;

                left++;
            }

            if (flips <= k) {
                maxLen = max(maxLen, right - left + 1);
            }
        }
        return maxLen;
    }
};