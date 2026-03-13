class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        set<string> operators = {"+", "-", "*", "/"};
        stack<int> stk;
        for (string str : tokens) {
            if (operators.find(str) != operators.end()) {
                // is an operator
                int operand1 = stk.top();
                stk.pop();
                int operand2 = stk.top();
                stk.pop();
                int result = 0;
                if (str == "+") {
                    result = operand2 + operand1;
                } else if (str == "-") {
                    result = operand2 - operand1;
                } else if (str == "*") {
                    result = operand2 * operand1;
                } else {
                    result = operand2 / operand1;
                }
                stk.push(result);
            } else {
                // is a number
                stk.push(stoi(str));
            }
        }
        return stk.top();
    }
};