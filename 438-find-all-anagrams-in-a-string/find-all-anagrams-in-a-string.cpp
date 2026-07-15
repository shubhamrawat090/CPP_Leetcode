class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int m = p.size(), n = s.size();
        vector<int> freq(26, 0);
        int charCounted = 0;
        for (char ch : p) {
            freq[ch - 'a']--;
        }

        int left = 0;
        vector<int> ans;
        for (int right = 0; right < n; right++) {
            if (freq[s[right] - 'a'] < 0) {
                charCounted++;
            }
            freq[s[right] - 'a']++;

            while (charCounted == m) {
                int len = right - left + 1;
                if (len == m)
                    ans.push_back(left); // Window size is same as chars in p AND all
                                 // chars of p are in window
                if (freq[s[left] - 'a'] == 0) {
                    charCounted--;
                }
                freq[s[left] - 'a']--;
                left++;
            }
        }
        return ans;
    }
};