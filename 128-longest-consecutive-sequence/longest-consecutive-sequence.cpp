class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> values(nums.begin(), nums.end());
        int longest = 0;

        for (int num : values) {
            if (!values.count(num - 1)) {
                int current = num;
                int length = 1;

                while (values.count(current + 1)) {
                    ++current;
                    ++length;
                }

                longest = max(longest, length);
            }
        }

        return longest;
    }
};