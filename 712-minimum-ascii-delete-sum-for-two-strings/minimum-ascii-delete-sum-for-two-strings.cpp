class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int m = s1.size(), n = s2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + s1[i - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }

        string lcs;
        int lcsAsciiSum = 0;
        int i = m, j = n;
        while (i > 0 && j > 0) {
            if (s1[i - 1] == s2[j - 1]) {
                lcs.push_back(s1[i - 1]);
                lcsAsciiSum += s1[i - 1];
                i--;
                j--;
            } else if (dp[i - 1][j] > dp[i][j - 1]) {
                i--;
            } else {
                j--;
            }
        }

        int s1AsciiSum = 0;
        for (char ch : s1) {
            s1AsciiSum += ch;
        }
        int s2AsciiSum = 0;
        for (char ch : s2) {
            s2AsciiSum += ch;
        }

        cout << "s1AsciiSum: " << s1AsciiSum << endl;
        cout << "s2AsciiSum: " << s2AsciiSum << endl;
        cout << "lcs: " << lcs << endl;
        cout << "lcsAsciiSum: " << lcsAsciiSum << endl;

        return s1AsciiSum + s2AsciiSum - lcsAsciiSum - lcsAsciiSum;
    }
};