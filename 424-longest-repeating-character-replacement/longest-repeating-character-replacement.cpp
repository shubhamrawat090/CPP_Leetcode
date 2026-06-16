class Solution {
public:
    int characterReplacement(string s, int k) {
        int freq[26];

        int maxLen = 0;
        int maxCharCount = 0;

        int left = 0, right = 0;
        int n = s.size();

        while(right < n) {
            freq[s[right]-'A']++;
            maxCharCount = max(maxCharCount, freq[s[right]-'A']);
            if(right - left + 1 - maxCharCount > k) {
                // shrink
                freq[s[left]-'A']--;
                left++;
            }
            maxLen = max(maxLen, right-left+1);
            right++;
        }

        return maxLen;
    }
};