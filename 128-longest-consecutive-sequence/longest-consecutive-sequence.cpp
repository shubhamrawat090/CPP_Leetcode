class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        sort(nums.begin(), nums.end());

        int currMax = 1;
        int totalMax = 1;
        int i = 1; 
        while(i < n) {
            int prev = i-1;
            while(i < n && nums[i] == nums[i-1]) i++;
            if(i >= n) break;
            if(nums[prev] == nums[i] - 1) {
                currMax++;
            } else {
                currMax = 1;
            }

            totalMax = max(totalMax, currMax);
            i++;
        }
        return totalMax;
    }
};