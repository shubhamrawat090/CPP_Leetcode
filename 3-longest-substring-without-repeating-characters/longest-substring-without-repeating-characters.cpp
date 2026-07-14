class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_map<char, int> freq;
        int distinct = 0;
        int left = 0;
        int maxLen = 0;
        for(int right=0; right<n; right++) {
            // Not found || freq == 0 ==> a distinct char
            bool found = freq.find(s[right]) != freq.end();
            if(!found || freq[s[right]] == 0) {
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

            if(distinct == right-left+1) {
                maxLen = max(maxLen, right-left+1);
            }
        }
        return maxLen;
    }
};