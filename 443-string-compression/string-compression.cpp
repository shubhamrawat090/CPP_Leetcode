class Solution {
public:
    int compress(vector<char>& chars) {
        // ["a","a","b","b","c","c","c"]
        //                                i

        // currChar: 'c'
        // currFreq: 3

        // len = 2 + 2 + 2 = 6

        // --> maintain currChar, currFreq
        // --> if chars[i] == currChar: currFreq++
        //     else calculate len, currChar = chars[i], currFreq = 1
        // --> at the end just don't forget to add len for remaining currChar

        // ***** int len = len(currChar) + len(currFreq - in string form)  *****
        int len = 0;
        char currChar = chars[0];
        int currFreq = 0;

        int ptr = 0;

        for (char ch : chars) {
            if (ch == currChar) {
                currFreq++;
            } else {
                string numInString = to_string(currFreq);
                len++;
                if (currFreq > 1) {
                    len += numInString.size();
                }

                chars[ptr++] = currChar;

                if (currFreq > 1) {
                    for (int i = 0; i < numInString.size(); i++) {
                        chars[ptr++] = numInString[i];
                    }
                }

                currChar = ch;
                currFreq = 1;
            }
        }

        string numInString = to_string(currFreq);
        len++;
        if (currFreq > 1) {
            len += numInString.size();
        }

        chars[ptr++] = currChar;

        if (currFreq > 1) {
            for (int i = 0; i < numInString.size(); i++) {
                chars[ptr++] = numInString[i];
            }
        }

        return len;
    }
};