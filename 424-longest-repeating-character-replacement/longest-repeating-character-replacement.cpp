class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int left = 0, right = 0, maxCharCount = 0;
        int maxLen = 0;
        vector<int> freq(26, 0);
        while(right < n) {
            freq[s[right] - 'A']++;
            maxCharCount = max(maxCharCount, freq[s[right] - 'A']);
            if(right - left + 1 - maxCharCount > k) {
                freq[s[left] - 'A']--;
                left++;
            }
            maxLen = max(maxLen, right - left + 1);
            right++;
        }
        return maxLen;
    }
};