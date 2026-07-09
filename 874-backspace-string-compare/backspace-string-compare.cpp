class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int m = s.size(), n = t.size();
        int i = m-1, j = n-1;
        int skip_s = 0;
        int skip_t = 0;
        while(i >= 0 || j >= 0) {
            while(i >= 0) {
                if(s[i] == '#') {
                    skip_s++;
                    i--;
                } else if(skip_s > 0) {
                    skip_s--;
                    i--;
                } else { // a character
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
                } else { // a character
                    break; 
                }
            }

            char sCh = i < 0 ? '$' : s[i];
            char tCh = j < 0 ? '$' : t[j];

            if(sCh != tCh) return false;

            i--;
            j--;
        }

        return true;
    }
};