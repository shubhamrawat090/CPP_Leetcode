class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i=0; i<s.size(); i++) {
            char ch = s[i];
            // open
            if(ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            } else { // close
                if(st.empty()) return false; // no open available
                if(st.top() == '{' && ch != '}') return false;
                if(st.top() == '[' && ch != ']') return false;
                if(st.top() == '(' && ch != ')') return false;
                st.pop();
            }
        }
        return st.empty(); // at the end all the open should be cancelled out by closed
    }
};