class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int flips = 0;
        int start = 0;
        int maxLen = 0;

        for (int end = 0; end < n; end++) {
            if (nums[end] == 0) {
                flips++;
            }

            while (flips > k) {
                if (nums[start] == 0) {
                    // unflip 0->1
                    flips--;
                }
                start++;
            }

            maxLen = max(maxLen, end - start + 1);
        }
        return maxLen;
    }
};