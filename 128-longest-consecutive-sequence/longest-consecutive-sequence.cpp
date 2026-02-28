class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int ans = 0;

        for (int val : st) {
            // if previous number exists, not a sequence start
            if (st.find(val - 1) != st.end()) continue;

            int count = 1;
            while (st.find(val + count) != st.end()) {
                count++;
            }
            ans = max(ans, count);
        }
        return ans;
    }
};