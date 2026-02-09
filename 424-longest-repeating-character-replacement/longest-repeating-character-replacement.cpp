class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0, ans = 0, maxCount = 0;
        int count[26] = {0};
        for (int right = 0; right < s.size(); right++) {
            count[s[right] - 'A']++;
            maxCount = max(maxCount, count[s[right] - 'A']);

            // flips => minCount = range - maxCount = right-left+1 - maxCount
            while (right - left + 1 - maxCount > k) {
                count[s[left] - 'A']--;
                left++;
            }

            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};