class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();

        char currChar = chars[0];
        int currCount = 0;

        string compressed;
        for (int i = 0; i < n; i++) {
            if (chars[i] == currChar) {
                currCount++;
            } else {
                compressed.push_back(currChar);
                if (currCount > 1) {
                    compressed += to_string(currCount);
                }

                currCount = 1;
                currChar = chars[i];
            }
        }

        compressed.push_back(currChar);
        if (currCount > 1) {
            compressed += to_string(currCount);
        }

        int size = compressed.size();
        for (int i = 0; i < size; i++) {
            chars[i] = compressed[i];
        }
        return size;
    }
};