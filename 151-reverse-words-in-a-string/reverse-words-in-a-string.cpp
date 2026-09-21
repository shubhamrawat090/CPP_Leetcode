class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        int i = n - 1;

        string ans = "";

        while (i >= 0) {
            while (i >= 0 && s[i] == ' ')
                i--;

            string temp;
            while (i >= 0 && s[i] != ' ') {
                temp.push_back(s[i]);
                i--;
            }

            if (!temp.empty()) {
                reverse(temp.begin(), temp.end());

                ans += temp;
                ans.push_back(' ');
            }
        }

        ans.pop_back();

        return ans;
    }
};