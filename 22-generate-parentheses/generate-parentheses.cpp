class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        helper(ans, n, 0, 0, "");
        return ans;
    }

    void helper(vector<string>& ans, int n, int open, int close, string curr) {
        if(curr.size() == n * 2) {
            ans.push_back(curr);
            return;
        }

        if(open < n) {
            helper(ans, n, open + 1, close, curr + "(");
        }

        if(open > close) {
            helper(ans, n, open, close + 1, curr + ")");
        }
    }
};