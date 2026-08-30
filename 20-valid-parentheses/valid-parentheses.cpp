class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        unordered_map<char, char> closeToOpen;
        closeToOpen[')'] = '(';
        closeToOpen['}'] = '{';
        closeToOpen[']'] = '[';
        for(char ch: s) {
            if(ch == '(' || ch == '{' || ch == '[') {
                stk.push(ch);
            } else {
                if(stk.empty()) return false;

                // char open = '*';
                // char close = ch;
                // for(auto& entry: closeToOpen) {
                //     if(ch == entry.first) {
                //         open = entry.second;
                //         break;
                //     }
                // }
                char close = ch;
                char open = closeToOpen[ch];

                if(open == stk.top()) {
                    stk.pop();
                } else {
                    return false;
                }
            }
        }
        return stk.empty();
    }
};