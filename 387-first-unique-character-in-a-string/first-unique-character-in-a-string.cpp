class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }

        int n = s.size();
        int ans = -1;
        for (int i = 0; i < n; i++) {
            if (freq[s[i] - 'a'] == 1) {
                ans = i;
                break;
            }
        }

        return ans;
    }
};