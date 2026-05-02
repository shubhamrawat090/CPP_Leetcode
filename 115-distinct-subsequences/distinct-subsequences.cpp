class Solution {
public:
    int numDistinct(string s, string t) {
        // 🧠 What the question is REALLY asking?
        // “In how many ways can I pick characters from s (in order) to form t?”

        int m = s.size(), n = t.size();
        // dp[i][j] = number of ways to form t[0..j-1] from s[0..i-1]
        vector<vector<unsigned long long>> dp(m+1, vector<unsigned long long>(n+1, 0));

        // 🧠 Base Case (this is what most people miss)
        // dp[i][0] = 1
        // Why?
        // 👉 Empty string can be formed in exactly 1 way (pick nothing)   
        for(int i=0; i<=m; i++) {
            dp[i][0] = 1; // Pick nothing
        }

        for(int i=1; i<=m; i++) {
            for(int j=1; j<=n; j++) {
                if(s[i-1] == t[j-1]) {
                    dp[i][j] = (dp[i-1][j-1] + dp[i-1][j]);
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        return (int)dp[m][n];
    }
};