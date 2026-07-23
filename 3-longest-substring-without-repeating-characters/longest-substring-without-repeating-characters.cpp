class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        vector<int> freq(256, 0);
        int left = 0;
        int maxLen = 0;
        int distinct = 0;
        for (int right = 0; right < n; right++) {
            if (freq[s[right]] == 0) {
                distinct++;
            }
            freq[s[right]]++;
            while (distinct < right - left + 1) {
                freq[s[left]]--;
                if (freq[s[left]] == 0)
                    distinct--;
                left++;
            }
            if (distinct == right - left + 1)
                maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};