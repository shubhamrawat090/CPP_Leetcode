class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0, right = 0;
        int maxLen = 0;
        vector<int> map(2, 0);
        while(right < n) {
            map[nums[right]]++;

            if(map[0] > k) {
                map[nums[left]]--;
                left++;
            }

            if(map[0] <= k) {
                maxLen = max(maxLen, right - left + 1);
            }

            right++;
        }

        return maxLen;
    }
};