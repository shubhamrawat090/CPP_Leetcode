class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string curr;
        helper(n, ans, curr, 0, 0);
        return ans;
    }

    void helper(int n, vector<string>& ans, string curr, int open, int close) {
        if(curr.size() == n * 2) {
            ans.push_back(curr);
            return;
        }

        // open < n -> can add open bracket
        // open > close -> can add closed bracket
        if(open < n) {
            helper(n, ans, curr + '(', open + 1, close);
        }

        if(open > close) {
            helper(n, ans, curr + ')', open, close + 1);
        }
    }
};