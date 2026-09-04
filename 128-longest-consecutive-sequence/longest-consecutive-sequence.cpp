class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> values(nums.begin(), nums.end());
        int longest = 0;

        for (int num : values) {
            if (values.find(num - 1) == values.end()) {
                int current = num;
                int length = 1;

                while (values.find(current + 1) != values.end()) {
                    ++current;
                    ++length;
                }

                longest = max(longest, length);
            }
        }

        return longest;
    }
};