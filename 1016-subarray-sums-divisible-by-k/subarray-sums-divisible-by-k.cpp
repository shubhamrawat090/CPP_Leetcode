class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;
        unordered_map<int, int> sumIdx;
        sumIdx[0] = 1; // 0 remainder is left when we do EMPTY SUBARRAY(sum = 0) % k
        int count = 0;
        for(int i=0; i<n; i++) {
            sum += nums[i];

            int rem = sum % k;
            if(rem < 0) rem += k;
            count += sumIdx[rem];
            sumIdx[rem]++;
        }
        return count;
    }
};