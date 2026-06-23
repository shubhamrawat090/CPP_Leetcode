class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size();
        int m = p.size();

        if (m > n) return {};

        vector<int> pFreq(26, 0);
        vector<int> winFreq(26, 0);

        for (char ch : p)
            pFreq[ch - 'a']++;

        for (int i = 0; i < m; i++)
            winFreq[s[i] - 'a']++;

        vector<int> ans;

        if (pFreq == winFreq)
            ans.push_back(0);

        for (int i = m; i < n; i++) {
            winFreq[s[i] - 'a']++;
            winFreq[s[i - m] - 'a']--;

            if (pFreq == winFreq)
                ans.push_back(i - m + 1);
        }

        return ans;
    }
};