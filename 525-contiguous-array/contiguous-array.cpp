class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] == 0) {
                nums[i] = -1;
            }
        }
        return longestSubarray(nums, 0);
    }

    int longestSubarray(vector<int>& arr, int k) {
        unordered_map<long long, int> sumIdx;
        long long sum = 0;
        int ans = 0;

        for(int i = 0; i < arr.size(); i++) {
            sum += arr[i];

            // Case 1: subarray from index 0
            if(sum == k) {
                // ans = max(ans, i + 1);
                ans = i + 1;
            }

            // Case 2: subarray ending at i
            if(sumIdx.find(sum - k) != sumIdx.end()) {
                ans = max(ans, i - sumIdx[sum - k]);
            }

            // Store first occurrence only
            if(sumIdx.find(sum) == sumIdx.end()) {
                sumIdx[sum] = i;
            }
        }
        return ans;
    }
};