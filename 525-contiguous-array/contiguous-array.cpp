class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int maxLen = 0;
        int sum = 0;
        unordered_map<int, int> sumIdx;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i] == 0 ? -1 : 1;

            if (sum == 0) {
                maxLen = i + 1;
            }

            if (sumIdx.find(sum) != sumIdx.end()) {
                maxLen = max(maxLen, i - sumIdx[sum]);
            } else {
                sumIdx[sum] = i;
            }
        }
        return maxLen;
    }
};