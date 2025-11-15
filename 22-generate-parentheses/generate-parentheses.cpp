class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string str;
        helper(ans, str, 0, 0, n);
        return ans;
    }

    void helper(vector<string>& ans, string& str, int open, int close, int n) {
        if(open == n && close == n) {
            ans.push_back(str);
            return;
        }

        // Try open
        if(open < n) {
            str += '(';
            helper(ans, str, open + 1, close, n);
            str.pop_back();
        }
        // Try close
        if(open > close) {
            str += ')';
            helper(ans, str, open, close + 1, n);
            str.pop_back();
        }
    }
};