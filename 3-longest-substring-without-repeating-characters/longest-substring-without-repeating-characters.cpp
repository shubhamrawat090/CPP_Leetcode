class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> charFreq;
        int left = 0, ans = 0;
        for (int right = 0; right < s.size(); right++) {
            char rightChar = s[right];
            if (charFreq.find(rightChar) != charFreq.end()) {
                left = max(left, charFreq[rightChar]);
            }
            ans = max(ans, right - left + 1);
            charFreq[rightChar] =
                right + 1; // safe position where s[right] is not present
        }
        return ans;
    }
};