class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        stack<int> st;
        vector<string> ans;
        int num = 1;
        int i = 0;
        while(i < target.size() && num <= n) {
            if(st.empty()) {
                st.push(num++);
                ans.push_back("Push");
            }

            if(st.top() == target[i]) {
                i++;
                if(i >= target.size()) break;
                st.push(num++);
                ans.push_back("Push");
            } else {
                st.pop();
                ans.push_back("Pop");
                st.push(num++);
                ans.push_back("Push");
            }            
        }

        return ans;
    }
};