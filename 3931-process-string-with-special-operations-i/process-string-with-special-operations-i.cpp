class Solution {
public:
    string processStr(string s) {
        string res;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            char ch = s[i];
            if (ch == '*') {
                if (!res.empty()) {
                    res.pop_back();
                }
            } else if (ch == '#') {
                string temp = res;
                for (char ch : temp) {
                    res.push_back(ch);
                }
            } else if (ch == '%') {
                reverse(res.begin(), res.end());
            } else {
                res.push_back(ch);
            }
        }
        return res;
    }
};