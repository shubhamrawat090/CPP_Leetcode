class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> freq(128, 0); // 128 ascii characters
        for (char ch : t) {
            freq[ch]++;
        }

        int left = 0, count = t.size();
        int start = 0, minLen = INT_MAX;
        for (int right = 0; right < s.size(); right++) {
            if (freq[s[right]] > 0) {
                // this character is present in both t and s
                count--; // 1 char down
            }
            freq[s[right]]--; // we decrease down characters. So, the ones
                              // common in s and t will have freq = 0
            while (count == 0) { // All the chars are counted. count = 0 means that all
                        // the characters from t are found in s
                if (minLen > right - left + 1) {
                    minLen = right - left + 1;
                    start = left;
                }
                freq[s[left]]++;
                if (freq[s[left]] > 0) {
                    // greater than zero means that the matching char in both s and t is not included
                    count++; // we do count++ to say that there is 1 more character we haven't counted yet
                }
                left++; // shrinking the range
            }
        }
        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};