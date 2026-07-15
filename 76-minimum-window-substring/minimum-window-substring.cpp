class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size(), m = t.size();
        vector<int> freq(256, 0);
        int left = 0;
        int minLen = INT_MAX;
        int stIdx = -1;

        for(char ch: t) {
            freq[ch]--;
        }

        int matchCharCount = 0;
        for(int right=0; right<n; right++) {
            if(freq[s[right]] < 0) {
                matchCharCount++;
            }
            freq[s[right]]++;

            while(matchCharCount == m) {
                int len = right-left+1;
                if(len < minLen) {
                    stIdx = left;
                    minLen = len;
                }

                if(freq[s[left]] == 0) {
                    matchCharCount--;
                }
                freq[s[left]]--;
                left++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(stIdx, minLen);
    }
};