class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> mp;

        // Step 1: value -> indices mapping
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        vector<long long> ans(n, 0);

        // Step 2: process each group
        for (auto &it : mp) {
            vector<int>& idxs = it.second;
            int m = idxs.size();

            // prefix sum array
            vector<long long> prefix(m);
            prefix[0] = idxs[0];
            for (int i = 1; i < m; i++) {
                prefix[i] = prefix[i - 1] + idxs[i];
            }

            // compute answer
            for (int k = 0; k < m; k++) {
                long long x = idxs[k];

                long long left_count = k;
                long long right_count = m - k - 1;

                long long left_sum = (k > 0) ? prefix[k - 1] : 0;
                long long right_sum = prefix[m - 1] - prefix[k];

                ans[x] = 
                    x * left_count - left_sum +
                    right_sum - x * right_count;
            }
        }

        return ans;
    }
};