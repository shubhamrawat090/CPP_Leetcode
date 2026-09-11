class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size(), m = t.size();
        unordered_map<char, int> charFreq;

        // For small str start with negative freq
        for(int i=0; i<m; i++) {
            charFreq[t[i]]--;
        }

        int charsFound = 0;

        int startPt = -1;
        int minLen = INT_MAX;
        int left = 0;
        for(int right=0; right<n; right++) {
            if(charFreq[s[right]] < 0) {
                charsFound++;
            }

            charFreq[s[right]]++;

            while(left <= right && charsFound == m) {
                int len = right-left+1;
                if(len < minLen) {
                    minLen = len;
                    startPt = left;
                }

                charFreq[s[left]]--;
                if(charFreq[s[left]] < 0) charsFound--;
                left++;
            }
        }

        return startPt == -1 ? "" : s.substr(startPt, minLen);
    }
};