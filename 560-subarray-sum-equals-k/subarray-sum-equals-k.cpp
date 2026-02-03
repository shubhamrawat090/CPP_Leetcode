class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0, sum = 0;
        unordered_map<int, int> sumFreq;
        // empty subarray 
        sumFreq[0] = 1;
        for(int i=0; i<nums.size(); i++) {
            sum += nums[i];
            if(sumFreq.find(sum - k) != sumFreq.end()) {
                count += sumFreq[sum - k];
            }
            sumFreq[sum]++;
        }
        return count;
    }
};