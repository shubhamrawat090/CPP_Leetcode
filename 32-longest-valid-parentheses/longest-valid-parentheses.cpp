class Solution {
public:
    int longestValidParentheses(string s) {
        int open = 0, close = 0;
        int maxCountL2R = 0, count = 0;
        for(int i=0; i<s.size(); i++) {
            char ch = s[i];
            if(ch == '(') {
                open++;
            } else {
                close++;
            }

            if(open == close) {
                count = (open + close);
                maxCountL2R = max(count, maxCountL2R);
            } else if(open < close) {
                open = 0;
                close = 0;
                count = 0;
            }
        }

        int maxCountR2L = 0;
        count = 0, open = 0, close = 0;
        for(int i=s.size()-1; i>=0; i--) {
            char ch = s[i];
            if(ch == '(') {
                open++;
            } else {
                close++;
            }

            if(open == close) {
                count = (open + close);
                maxCountR2L = max(count, maxCountR2L);
            } else if(close < open) {
                open = 0;
                close = 0;
                count = 0;
            }
        }
        return maxCountL2R > maxCountR2L ? maxCountL2R : maxCountR2L;
    }
};