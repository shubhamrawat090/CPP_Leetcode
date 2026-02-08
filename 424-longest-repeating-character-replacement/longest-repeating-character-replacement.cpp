class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0;
        int ans = 0;
        int freqMap[26] = {0};
        int mostOccur = 0;
        for (int right = 0; right < s.size(); right++) {
            freqMap[s[right] - 'A']++;
            mostOccur = max(mostOccur, freqMap[s[right] - 'A']);

            // flips = lessOccur = total(range) - mostOccur
            while (right - left + 1 - mostOccur > k) {
                freqMap[s[left] - 'A']--;
                left++;
            }

            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};