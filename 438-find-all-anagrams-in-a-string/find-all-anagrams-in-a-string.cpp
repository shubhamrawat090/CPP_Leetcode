class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size();
        int m = p.size();

        unordered_map<char, int> charFreq;
        for (char ch : p) {
            charFreq[ch]++;
        }
        unordered_map<char, int> currCharFreq = charFreq;

        int left = 0, right = 0;
        vector<int> ans;
        while (right < n) {
            if (currCharFreq.find(s[right]) != currCharFreq.end()) {
                // Char is present in string p
                currCharFreq[s[right]]--;
                while (currCharFreq[s[right]] < 0) {
                    // extra character found in window --> start shrinking 1 by
                    // 1
                    if (currCharFreq.count(s[left])) currCharFreq[s[left]]++;
                    left++;
                }
                    
                if (right-left+1 == m) {
                    // All characters found from p
                    ans.push_back(left);
                }
            } else {
                // Char is not present in p --> shrink the entire window
                currCharFreq = charFreq; // restore frequencies
                left = right + 1;
            }
            right++;
        }

        return ans;
    }
};