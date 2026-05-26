class Solution {
public:
    int numberOfSpecialChars(string word) {
        pair<bool, bool> charOccurrence[26] = {{false, false}};
        for (char ch : word) {
            int lower = ch - 'a';
            int upper = ch - 'A';
            if (upper >= 0 && upper < 26) {
                charOccurrence[upper].second = true;
            }
            if (lower >= 0 && lower < 26) {
                charOccurrence[lower].first = true;
            }
        }

        int count = 0;
        for (int i = 0; i < 26; i++) {
            if (charOccurrence[i].first == true &&
                charOccurrence[i].second == true) {
                count++;
            }
        }

        return count;
    }
};