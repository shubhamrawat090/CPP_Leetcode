class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        helper(n, ans, 0, 0, "");
        return ans;
    }

    void helper(int& n, vector<string>& ans, int open, int close, string curr) {
        if(curr.size() == n * 2) {
            ans.push_back(curr);
            return;
        }

        if(open < n) {
            // add open
            helper(n, ans, open+1, close, curr + '(');
        }

        if(open > close) {
            // add close
            helper(n, ans, open, close+1, curr + ')');
        }
    }
};