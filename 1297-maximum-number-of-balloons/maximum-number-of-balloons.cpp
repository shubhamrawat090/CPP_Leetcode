class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int freq[26] = {0};
        for (char ch : text) {
            freq[ch - 'a']++;
        }

        string str = "balloon";
        int minOccur = INT_MAX;
        for (char ch : str) {
            bool is_L_O = (ch == 'l' || ch == 'o');
            int charFreq = is_L_O ? freq[ch - 'a'] / 2 : freq[ch - 'a'];
            minOccur = min(minOccur, charFreq);
        }

        return minOccur;
    }
};