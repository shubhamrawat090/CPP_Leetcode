class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0;
        unordered_map<char, int> valIdx;
        int left = 0;
        for(int right = 0; right < s.size(); right++) {
            char ch = s[right];
            if(valIdx.find(ch) != valIdx.end()) {
                left = max(left, valIdx[ch]);
            }
            int len = right - left + 1;
            maxLen = max(len, maxLen);
            valIdx[ch] = right + 1;
        }
        return maxLen;
    }
};