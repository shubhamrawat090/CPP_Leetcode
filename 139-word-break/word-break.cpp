class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        int n = s.size();
        // return recursive(s, wordSet, 0, n - 1);
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return memoized(s, wordSet, 0, n - 1, dp);
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