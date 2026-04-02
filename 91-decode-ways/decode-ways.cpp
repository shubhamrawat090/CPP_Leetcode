class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if(n == 0 || s[0] == '0') {
            // no way to decode if starts with '0'
            return 0; 
        }
        vector<int> dp(n+1, 0);
        dp[0] = dp[1] = 1;
        for(int i=2; i<=n; i++) {
            // count single digit
            if(s[i-1] >= '1' && s[i-1] <= '9') {
                dp[i] += dp[i-1];
            }
            
            // count double digit
            if(s[i-2] == '1' || (s[i-2] == 
            '2' && s[i-1] <= '6')) {
                dp[i] += dp[i-2];
            }
        }

        return dp[n];
    }
};