class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m = s1.size(), n = s2.size();
        vector<int> freq(26, 0);
        int charCounted = 0;
        for (char ch : s1) {
            freq[ch - 'a']--;
        }

        int left = 0;
        for (int right = 0; right < n; right++) {
            if (freq[s2[right] - 'a'] < 0) {
                charCounted++;
            }
            freq[s2[right] - 'a']++;

            while (charCounted == m) {
                int len = right - left + 1;
                if (len == m)
                    return true; // Window size is same as chars in s1 AND all
                                 // chars of s1 are in window
                if (freq[s2[left] - 'a'] == 0) {
                    charCounted--;
                }
                freq[s2[left] - 'a']--;
                left++;
            }
        }
        return false;
    }
};