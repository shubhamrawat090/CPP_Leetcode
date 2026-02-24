class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0, right = 0;
        int n = s.size();
        int maxLen = 0;
        int maxCharCount = 0;
        vector<int> map(26, 0);
        while(right < n) {
            map[s[right] - 'A']++;
            maxCharCount = max(maxCharCount, map[s[right] - 'A']);

            int range = right-left+ 1;
            int leastCharCount = range - maxCharCount;

            if(leastCharCount > k) {
                map[s[left] - 'A']--;
                left++;
            }

            if(leastCharCount <= k) {
                maxLen = max(range, maxLen);
            }

            right++;
        }
        return maxLen;
    }
};