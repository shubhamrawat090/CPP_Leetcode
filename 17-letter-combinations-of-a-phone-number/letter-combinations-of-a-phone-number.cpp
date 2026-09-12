class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        unordered_map<char, string> digitMappings;
        digitMappings['2'] = "abc";
        digitMappings['3'] = "def";
        digitMappings['4'] = "ghi";
        digitMappings['5'] = "jkl";
        digitMappings['6'] = "mno";
        digitMappings['7'] = "pqrs";
        digitMappings['8'] = "tuv";
        digitMappings['9'] = "wxyz";
        helper(digits, digitMappings, 0, ans, "");
        return ans;
    }

    void helper(string& digits, unordered_map<char, string>& digitMappings, int i, vector<string>& ans, string curr) {
        int n = digits.size();
        if(i == n) {
            ans.push_back(curr);
            return;
        }

        string strMapping = digitMappings[digits[i]];
        for(auto& ch: strMapping) {
            curr.push_back(ch);
            helper(digits, digitMappings, i+1, ans, curr);
            curr.pop_back();
        }
    }
};