class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string curr;
        helper(ans, n, 0, 0, curr);
        return ans;
    }

    void helper(vector<string>& ans, int n, int open, int close, string& curr) {
        if(curr.size() == 2 * n) {
            ans.push_back(curr);
            return;
        }

        // Try to add open brackets
        if(open < n) {
            curr.push_back('(');
            helper(ans, n, open+1, close, curr);
            curr.pop_back();
        }

        // Try to add close brackets
        if(close < open) {
            curr.push_back(')');
            helper(ans, n, open, close+1, curr);
            curr.pop_back();
        }
    }
};