class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        int n = s.size();
        // return recursive(s, wordSet, 0, n - 1);
        // vector<vector<int>> dp(n, vector<int>(n, -1));
        // return memoized(s, wordSet, 0, n - 1, dp);
        return tabulate(s, wordSet, n);
    }

    bool tabulate(string& s, unordered_set<string>& wordSet, int n) {
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        // len = current substring length
        for (int len = 1; len <= n; len++) {

            for (int start = 0; start + len - 1 < n; start++) {

                int end = start + len - 1;

                for (int i = start; i <= end; i++) {

                    // LEFT WORD CASE
                    string leftPart = s.substr(start, i - start + 1);

                    if (wordSet.count(leftPart)) {

                        // remaining right side empty
                        if (i == end) {
                            dp[start][end] = true;
                            break;
                        }

                        // solve remaining right side
                        if (dp[i + 1][end]) {
                            dp[start][end] = true;
                            break;
                        }
                    }

                    // RIGHT WORD CASE
                    string rightPart = s.substr(i, end - i + 1);

                    if (wordSet.count(rightPart)) {

                        // remaining left side empty
                        if (i == start) {
                            dp[start][end] = true;
                            break;
                        }

                        // solve remaining left side
                        if (dp[start][i - 1]) {
                            dp[start][end] = true;
                            break;
                        }
                    }
                }
            }
        }

        return dp[0][n - 1];
    }

    bool memoized(string& s, unordered_set<string>& wordSet, int start, int end,
                  vector<vector<int>>& dp) {
        int n = s.size();
        if (start > end)
            return true;

        if (dp[start][end] != -1)
            return dp[start][end];

        for (int i = start; i <= end; i++) {
            // left part - present in wordSet
            string leftPart = s.substr(start, i - start + 1);
            if (wordSet.count(leftPart) > 0) {
                if (memoized(s, wordSet, i + 1, end, dp))
                    return dp[start][end] = true;
            }

            string rightPart = s.substr(i, end - i + 1);
            // right part - present in wordSet
            if (wordSet.count(rightPart) > 0) {
                if (memoized(s, wordSet, start, i - 1, dp))
                    return dp[start][end] = true;
            }
        }
        return dp[start][end] = false;
    }

    bool recursive(string& s, unordered_set<string>& wordSet, int start,
                   int end) {
        int n = s.size();
        if (start > end)
            return true;

        for (int i = start; i <= end; i++) {
            // left part - present in wordSet
            string leftPart = s.substr(start, i - start + 1);
            if (wordSet.count(leftPart) > 0) {
                if (recursive(s, wordSet, i + 1, end))
                    return true;
            }

            string rightPart = s.substr(i, end - i + 1);
            // right part - present in wordSet
            if (wordSet.count(rightPart) > 0) {
                if (recursive(s, wordSet, start, i - 1))
                    return true;
            }
        }
        return false;
    }
};