class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> sumFreq;
        int prefixSum = 0;
        int count = 0;
        sumFreq[0] = 1;
        for (int i = 0; i < nums.size(); i++) {
            prefixSum += nums[i];
            int remove = prefixSum - k;
            count += sumFreq[remove];
            sumFreq[prefixSum]++;
        }
        return count;
    }
};