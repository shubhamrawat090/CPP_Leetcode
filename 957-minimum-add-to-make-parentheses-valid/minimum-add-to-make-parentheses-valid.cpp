class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0, close = 0;
        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];
            if (ch == '(') {
                // count OPEN
                open++;
            } else {
                // CLOSE
                if (open > 0) {
                    // check if any open is available to balance
                    open--;
                } else {
                    // count CLOSE which cannot be balanced with an open
                    close++;
                }
            }
        }
        return open + close; // at the end, AFTER BALANCING ALL POSSIBLE OPEN WITH CLOSE, check which are remaining => will be the minimum adds needed
    }
};