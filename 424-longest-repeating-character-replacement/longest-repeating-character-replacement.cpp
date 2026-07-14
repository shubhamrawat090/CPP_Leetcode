class Solution {
public:
    int characterReplacement(string s, int k) {
        // OPTIMISATION 1:
        // Stop recomputing maxOccur(max freq),        O(N + N) * 26 ===> O(N +
        // N) We need    window_len - maxFreq <= k suppose: window_len = 5,
        // maxFreq = 3, REPLACEMENTS = 2    **ALLOWED: k = 2** next best answer
        // has to be GREATER THAN window_len so, 6 or 7 or 8 ..... Even if for
        // same window_len = 5, we increase maxFreq = 4 The REPLACEMENTS = 5-4 =
        // 1 IS LESS THAN k = 2, WHICH IS GOOD FOR US ONLY

        // OPTIMISATION 2
        // while() --> if()                            O(N + N) ==> O(N)
        // Can remove while(SHRINKING LEFT) and use only if(SHRINKING LEFT)
        // Suppose: (AAABA) BCB, k = 1 was the window; ANS = 5
        // Next answer has to be greater for us to consider it
        // What while does is shrink from 5->4->3... which is not need
        // We use if() and shrink only once : 5->4: A (AABA) BCB
        // When we add next char: the window again becomes 5: A (AABAB) CB.
        // WE MAKE SURE TO NEVER DECREASE IT BELOW 5

        vector<int> freq(26, 0);
        int n = s.size();
        int left = 0;
        int maxLen = 0;
        int maxOccur = 0;
        for (int right = 0; right < n; right++) {
            freq[s[right] - 'A']++;
            maxOccur = max(maxOccur, freq[s[right] - 'A']);

            // OPTIMISATION - 2, O(N+N) --> O(N)
            // while (right - left + 1 - maxOccur > k) {
            if (right - left + 1 - maxOccur > k) {
                freq[s[left] - 'A']--;

                // OPTIMISATION - 1, O(N)*26 ==> O(N): Remove 26 multiplier
                // maxOccur = 0;
                // for(int i=0; i<26; i++) {
                //     maxOccur = max(maxOccur, freq[i]);
                // }
                left++;
            }

            if (right - left + 1 - maxOccur <= k) {
                maxLen = max(maxLen, right - left + 1);
            }
        }
        return maxLen;
    }
};