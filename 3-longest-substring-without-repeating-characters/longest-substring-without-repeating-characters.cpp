class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        vector<int> freq(256, 0);
        int distinct = 0;
        int left = 0;
        int maxLen = 0;
        for(int right=0; right<n; right++) {
            // freq == 0 ==> a distinct char
            if(freq[s[right]] == 0) {
                distinct++;
            }
            freq[s[right]]++;

            // Shrink -> window > distinct chars
            while(right-left+1 > distinct) {
                freq[s[left]]--;
                if(freq[s[left]] == 0) {
                    distinct--; // Removal of all occurrences of a char from window
                }
                left++;
            }

            if(distinct == right-left+1) { // If window size == no. of distinct chars --> WE FOUND A VALID WINDOW
                maxLen = max(maxLen, right-left+1);
            }
        }
        return maxLen;
    }
};