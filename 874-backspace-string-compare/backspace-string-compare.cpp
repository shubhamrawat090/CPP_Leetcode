class Solution {
public:
    bool backspaceCompare(string s, string t) {
        // Start from back
        // for string s, iterator i
        // if last char is # --> count skip_s++
        // if not # but there is skip_s left -> skip the char i--
        // if not # and not skip_s left -> STOP
        // DO SIMILAR FOR string t, iterator j
        // if both jand j at -1 ==> MEANS CORRECT
        // if i at -1 and j >= 0 ==> return false
        // if i, j >= 0 and s[i] != t[j] (AFTER ALL THE SKIPS) ==> return false
        // Otherwise, i--, j-- ==> CONTINUE ONE
        int m = s.size(), n = t.size();
        int i = m-1, j = n-1;

        // OR because there can be some characters left in 1 string and they can all be backspaced
        int skip_s = 0, skip_t = 0;
        while(i >= 0 || j >= 0) {
            while(i >= 0) {
                if(s[i] == '#') {
                    skip_s++;
                    i--;
                } else if(skip_s > 0) {
                    skip_s--;
                    i--;
                } else {
                    break;
                }
            }

            while(j >= 0) {
                if(t[j] == '#') {
                    skip_t++;
                    j--;
                } else if(skip_t > 0) {
                    skip_t--;
                    j--;
                } else {
                    break;
                }
            }

            char chS = i < 0 ? '$' : s[i];
            char chT = j < 0 ? '$' : t[j];

            if(chS != chT) return false;

            i--, j--;
        }

        return true;
    }
};