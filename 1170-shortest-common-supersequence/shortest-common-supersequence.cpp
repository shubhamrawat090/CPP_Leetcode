class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int m = str1.size(), n = str2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1));
        for(int i=0; i<=m; i++) {
            for(int j=0; j<=n; j++) {
                if(i == 0 || j == 0) {
                    dp[i][j] = 0;
                } else if(str1[i-1] == str2[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        // get the lcs
        return getSCS(str1, str2, dp);
    }

    string getSCS(string& str1, string& str2, vector<vector<int>>& dp) {
        int m = str1.size(), n = str2.size();
        int i = m, j = n;
        string scs = "";
        while(i > 0 && j > 0) {
            if(str1[i-1] == str2[j-1]) {
                scs.push_back(str1[i-1]);
                // go to top diagonal
                i--;
                j--;
            } else if(dp[i-1][j] > dp[i][j-1]) {
                // top one is bigger, go top
                scs.push_back(str1[i-1]);
                i--;
            } else {
                // bottom one is bigger, go bottom
                scs.push_back(str2[j-1]);
                j--;
            }
        }
        // push remaining str1 char
        while(i > 0) {
            i--;
            scs.push_back(str1[i]);
        }
        // push remaining str2 char
        while(j > 0) {
            j--;
            scs.push_back(str2[j]);
        }
        reverse(scs.begin(), scs.end());
        return scs;
    }
};