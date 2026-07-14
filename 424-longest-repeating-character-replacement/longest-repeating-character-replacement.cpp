class Solution {
public:
    int characterReplacement(string s, int k) {
        //  l
        // AABABBA    k=1
        //      r
        // maxLen = 4, maxOccur = 3
        // freq: A-3, B-2
        vector<int> freq(26, 0);
        int n = s.size();
        int left = 0;
        int maxLen = 0;
        int maxOccur = 0;
        for(int right=0; right<n; right++) {
            freq[s[right]-'A']++;
            maxOccur = max(maxOccur, freq[s[right]-'A']);
            if(right-left+1-maxOccur > k) {
                freq[s[left]-'A']--;
                for(int i=0; i<26; i++) {
                    maxOccur = max(maxOccur, freq[i]);
                }
                left++;
            }
            maxLen = max(maxLen, right-left+1);
        }
        return maxLen;
    }
};