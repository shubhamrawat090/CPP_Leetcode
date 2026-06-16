class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size(); // large string len
        int m = t.size(); // small string len
        if (m > n)
            return "";

        vector<int> freq(128, 0);
        // Changing the starting line for small str chars
        for (char ch : t) {
            freq[ch]--;
        }

        int left = 0, right = 0;
        int count = 0;
        int minLen = INT_MAX;
        int stPt = -1;
        while (right < n) {
            if (freq[s[right]] < 0) {
                count++; // counting chars of small string
            }
            freq[s[right]]++;
            // we can shrink till we have all the chars of small str
            while (count == m) {
                int range = right - left + 1;
                if (range < minLen) {
                    stPt = left;
                    minLen = range;
                }
                freq[s[left]]--;
                // a char from small str has been removed from window while
                // shrinking
                if (freq[s[left]] < 0) {
                    count--;
                }
                left++;
            }
            right++;
        }
        return stPt == -1 ? "" : s.substr(stPt, minLen);
    }
};