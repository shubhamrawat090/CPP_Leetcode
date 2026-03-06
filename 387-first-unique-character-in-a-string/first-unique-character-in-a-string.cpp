class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> charFreq;
        int n = s.size();
        for(char ch: s) {
            charFreq[ch]++;
        }

        for(int i=0; i<n; i++) {
            if(charFreq[s[i]] == 1) {
                return i;
            }
        }

        return -1;
    }
};