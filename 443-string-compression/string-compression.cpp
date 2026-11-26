class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();

        int compressIdx = 0;

        char currChar = chars[0];
        int currCount = 0;

        for (int i = 0; i < n; i++) {
            if (chars[i] == currChar) {
                currCount++;
            } else {
                chars[compressIdx++] = currChar;
                if (currCount > 1) {
                    string count = to_string(currCount);
                    for (char c : count) {
                        chars[compressIdx++] = c;
                    }
                }

                currCount = 1;
                currChar = chars[i];
            }
        }

        chars[compressIdx++] = currChar;
        if (currCount > 1) {
            string count = to_string(currCount);
            for (char c : count) {
                chars[compressIdx++] = c;
            }
        }

        return compressIdx;
    }
};