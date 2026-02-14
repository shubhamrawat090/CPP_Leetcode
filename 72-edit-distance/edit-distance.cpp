class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        // vector<vector<int>> dp(m+1, vector<int>(n+1));
        vector<int> prev(n+1);
        for(int j=0; j<=n; j++) {
            prev[j] = j;
        }

        for(int i=1; i<=m; i++) {
            vector<int> curr(n+1);
            curr[0] = i;
            for(int j=1; j<=n; j++) {
                if(word1[i-1] == word2[j-1]) {
                    curr[j] = prev[j-1];
                } else {
                    curr[j] = 1 + min(prev[j-1], min(prev[j], curr[j-1]));
                }
            }
            prev = curr;
        }

        return prev[n];
    }
};