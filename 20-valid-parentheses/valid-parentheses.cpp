class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i=0; i<s.size(); i++) {
            // open
            if(s[i] == '(' || s[i] == '{' || s[i] == '[') {
                st.push(s[i]);
            } else {
                // check matching
                if(st.size() == 0) return false;
                char topElem = st.top();
                st.pop();
                if(!(topElem == '(' && s[i] == ')' ||
                topElem == '{' && s[i] == '}' ||
                topElem == '[' && s[i] == ']')) {
                    return false;
                } 
            }
        }
        return st.size() == 0;
    }
};