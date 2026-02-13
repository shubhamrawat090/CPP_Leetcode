class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string curr = "";
        helper(n, ans, 0, 0, curr);
        return ans;
    }

    void helper(int& n, vector<string>& ans, int open, int close, string& curr) {
        if(curr.size() == n * 2) {
            ans.push_back(curr);
            return;
        }

        if(open < n) {
            // add open
            curr.push_back('(');
            helper(n, ans, open+1, close, curr);
            curr.pop_back();
        }

        if(open > close) {
            // add close
            curr.push_back(')');
            helper(n, ans, open, close+1, curr);
            curr.pop_back();
        }
    }
};