class Solution {
public:
    int longestValidParentheses(string s) {
        int maxLen = 0;
        int close = 0, open = 0;
        int n = s.size();
        // Left to right
        for(int i=0; i<n; i++) {
            if(s[i] == '(') {
                open++;
            } else {
                close++;
            }

            if(open == close) {
                int count = open + close;
                maxLen = max(maxLen, count); 
            } else if(close > open) {
                // reset 
                open = 0;
                close = 0;
            }
        }

        // Right to left
        close = 0, open = 0;
        for(int i=n-1; i>=0; i--) {
            if(s[i] == '(') {
                open++;
            } else {
                close++;
            }

            if(open == close) {
                int count = open + close;
                maxLen = max(maxLen, count); 
            } else if(open > close) {
                // reset 
                open = 0;
                close = 0;
            }
        }

        return maxLen;
    }
};