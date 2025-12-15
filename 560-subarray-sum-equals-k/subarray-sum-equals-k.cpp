class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // return usingPrefixSum(nums, k);
        return withoutUsingPrefixSum(nums, k);
    }

    int withoutUsingPrefixSum(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        unordered_map<int, int> mp;

        int sum = 0;
        for(int i=0; i<n; i++) {
            sum += nums[i];
            if(sum == k) count++;

            if(mp.find(sum - k) != mp.end()) {
                count += mp[sum - k];
            }

            mp[sum]++;
        }

        return count;
    }

    int usingPrefixSum(vector<int>& nums, int k) {
        int n = nums.size();
        int prefix[n];
        
        int count = 0;

        // Generate prefix sum array (BOTH WAYS ARE CORRECT TO GENERATE PREFIX SUM ARRAY)
        // int sum = 0;
        // for(int i=0; i<n; i++) {
        //     sum += nums[i];
        //     prefix[i] = sum;
        // }

        prefix[0] = nums[0];
        for(int i=1; i<n; i++) {
            prefix[i] = prefix[i-1] + nums[i];
        }

        unordered_map<int, int> mp; // prefixSum --> freq map
        for(int i=0; i<n; i++) {
            // Direct sum check
            if(prefix[i] == k) count++;

            // Check Indirect sum --> check if prefix[i] - k is present already or not
            if(mp.find(prefix[i] - k) != mp.end()) {
                count += mp[prefix[i] - k];
            }

            mp[prefix[i]]++;
        }

        return count;
    }
};