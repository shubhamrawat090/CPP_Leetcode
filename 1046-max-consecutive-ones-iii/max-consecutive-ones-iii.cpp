class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> freqMap;
        int start = 0;
        int maxLen = 0;
        for(int end = 0; end < n; end++) {
            freqMap[nums[end]]++;

            while(freqMap[0] > k) {
                freqMap[nums[start]]--;
                if(freqMap[nums[start]] == 0) {
                    freqMap.erase(nums[start]);
                }
                start++;
            }

            maxLen = max(maxLen, end - start + 1);
        }
        return maxLen;
    }
};