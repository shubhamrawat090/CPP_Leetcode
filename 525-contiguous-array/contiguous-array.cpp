class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        // Change 0 -> -1
        // Question changes to find longest subarray where sum = 0
        int k = 0;
        int n = nums.size();
        unordered_map<int, int> sumIdx;
        sumIdx[0] = -1;
        int maxLen = 0;
        int sum = 0;
        for(int i=0; i<n; i++) {
            sum += (nums[i] == 0) ? -1 : 1;
            if(sumIdx.find(sum-k) != sumIdx.end()) {
                maxLen = max(maxLen, i - sumIdx[sum-k]);
            }

            if(sumIdx.find(sum) == sumIdx.end()) {
                sumIdx[sum] = i; // We store first occurrence only. Because we need shortest length
            }
            
        }
        return maxLen;
    }
};