class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if(n == 0) return 0;
        int maxCount = 1, count = 1;
        for (int i = n - 1; i > 0; i--) {
            if (nums[i - 1] != nums[i]) {
                if (nums[i - 1] == nums[i] - 1) {
                    count++;
                } else {
                    count = 1;
                }
            }
            maxCount = max(count, maxCount);
        }
        return maxCount;
    }
};