class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;

        int n = words.size();
        int i = 0;

        while (i < n) {

            // --------------------------------
            // Find all words that fit this line
            // --------------------------------

            int j = i;
            int currLen = 0;

            while (j < n) {
                int wordLen = words[j].size();

                // j - i = number of spaces needed
                // between the words
                if (currLen + wordLen + (j - i) <= maxWidth) {
                    currLen += wordLen;
                    j++;
                }
                else {
                    break;
                }
            }

            int wordCount = j - i;
            int gaps = wordCount - 1;

            string line;

            // --------------------------------
            // Last line
            // --------------------------------

            if (j == n) {

                for (int k = i; k < j; k++) {
                    line += words[k];

                    if (k < j - 1)
                        line += ' ';
                }

                line += string(maxWidth - line.size(), ' ');
            }

            // --------------------------------
            // One-word line
            // --------------------------------

            else if (wordCount == 1) {

                line = words[i];
                line += string(maxWidth - line.size(), ' ');
            }

            // --------------------------------
            // Fully justified line
            // --------------------------------

            else {

                int totalSpaces = maxWidth - currLen;

                int baseSpace = totalSpaces / gaps;
                int extraSpace = totalSpaces % gaps;

                for (int k = i; k < j; k++) {

                    line += words[k];

                    if (k < j - 1) {

                        int spaces = baseSpace;

                        // Leftmost gaps get the extra spaces
                        if (extraSpace > 0) {
                            spaces++;
                            extraSpace--;
                        }

                        line += string(spaces, ' ');
                    }
                }
            }

            ans.push_back(line);

            // Move to the next line
            i = j;
        }

        return ans;
    }
};