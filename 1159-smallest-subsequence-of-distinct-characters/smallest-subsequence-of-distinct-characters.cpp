class Solution {
public:
    string smallestSubsequence(string s) {
        stack<char> st;
        vector<int> freq(26, 0);
        vector<bool> inStack(26, false);

        for(char ch: s) {
            freq[ch - 'a']++;
        }

        for(char ch: s) {
            freq[ch - 'a']--;

            if(inStack[ch - 'a'] == true) continue;

            while(!st.empty() && st.top() >= ch && freq[st.top() - 'a'] > 0) {
                char remove = st.top();
                st.pop();
                inStack[remove - 'a'] = false;
            }

            st.push(ch);
            inStack[ch - 'a'] = true;
        }

        int size = st.size();
        string ans(size, ' ');

        int i = size-1;
        while(!st.empty()) {
            char remove = st.top();
            st.pop();
            ans[i] = remove;
            i--;
        }

        return ans;
    }
};