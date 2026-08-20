class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> sumFreq;
        sumFreq[0] = 1;

        int sum = 0;
        int count = 0;
        for (auto& num : nums) {
            sum += num;
            count += sumFreq[sum - k];
            sumFreq[sum]++;
        }

        return count;
    }
};