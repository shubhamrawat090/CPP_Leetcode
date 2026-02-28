class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> freq;
        for(char ch: s) {
            freq[ch]++;
        }

        for(char ch: t) {
            freq[ch]--;
        }

        for(auto entry: freq) {
            if(entry.second != 0) return false;
        }

        return true;
    }
};