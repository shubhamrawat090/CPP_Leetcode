class Solution {
public:
    string decodeString(string s) {
        // number -> push stack
        // [ -> push stack
        // char -> push stack
        // ] -> DO THE FOLLOWING
        // Keep popping and appending till you get [
        // Ex: 2[ab -> keep popping and get "b" then "ba"
        // Ignore the [
        // Next pop is the LAST ONE -> get '2' use stoi('2') ==> 2
        // LOOP(in reverse): "ba" --> TILL THE INTEGER TIMES
        // Push back in stack
        // REPEAT THIS TILL STRING IS FINISHED.

        // Remaining in stack is the resultant string(in reverse)

        stack<char> stk;
        int n = s.size();
        for(int i=0; i<n; i++) {
            char ch = s[i];
            if(ch == ']') {
                string oper = "";
                while(stk.top() != '[') {
                    oper.push_back(stk.top());
                    stk.pop();
                }
                // Remove [
                stk.pop();

                // Get num
                string numStr;
                while(!stk.empty() && stk.top() >= '0' && stk.top() <= '9') {
                    numStr.push_back(stk.top());
                    stk.pop();
                }
                reverse(numStr.begin(), numStr.end());
                int num = stoi(numStr);

                int operSize = oper.size();
                while(num--) {
                    for(int i=operSize-1; i>=0; i--) {
                        stk.push(oper[i]);
                    }
                }
            } else {
                stk.push(ch);
            }
        } 


        string finalResult;
        while(!stk.empty()) {
            finalResult.push_back(stk.top());
            stk.pop();
        }
        reverse(finalResult.begin(), finalResult.end());
        return finalResult;
    }
};