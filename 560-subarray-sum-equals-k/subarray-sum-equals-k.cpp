class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> sumFreq;
        int sum = 0;
        int count = 0;
        sumFreq[0] = 1;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            int remove = sum - k;
            count += sumFreq[remove];
            sumFreq[sum]++;
        }
        return count;
    }
};