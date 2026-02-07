class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> charIdx;
        int start = 0, end = 0;
        int maxLen = 0;
        int n = s.size();
        while (end < n) {
            if (charIdx.find(s[end]) != charIdx.end()) {
                start = max(start, charIdx[s[end]]);
            }
            maxLen = max(end-start+1, maxLen);
            charIdx[s[end]] = end + 1;
            end++;
        }
        return maxLen;
    }
};