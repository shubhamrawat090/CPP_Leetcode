class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0, count = 0;
        unordered_map<int, int> sumFreq;
        // sumFreq[0] = 1; // empty subarray with sum = 0;
        for(int num: nums) {
            sum += num;

            if(sum == k) {
                count++;
            }

            if(sumFreq.find(sum - k) != sumFreq.end()) {
                count += sumFreq[sum - k];
            }

            sumFreq[sum]++;
        }
        return count;
    }
};