class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;

        for (int i = 0; i < tokens.size(); i++) {
            string ch = tokens[i];
            if (ch == "+" || ch == "-" || ch == "*" || ch == "/") {
                // NOTE: Since we pushed in stack so the first value you pop is actually num2 and not num1;
                int num2 = stk.top();
                stk.pop();
                int num1 = stk.top();
                stk.pop();
                int ans = 0;
                switch (ch[0]) {
                case '+':
                    ans = num1 + num2;
                    break;
                case '-':
                    ans = num1 - num2;
                    break;
                case '*':
                    ans = num1 * num2;
                    break;
                case '/':
                    ans = num1 / num2;
                    break;
                default:
                    break;
                }
                stk.push(ans);
            } else {
                int num = stoi(ch);
                stk.push(num);
            }
        }
        int ans = stk.top();
        return ans;
    }
};