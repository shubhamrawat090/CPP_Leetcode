class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        int t = 0;
        for(int num=1; num<=n and t < target.size(); num++) {
            ans.push_back("Push");
            if(num != target[t]) {
                // POP
                ans.push_back("Pop");
            } else {
                t++;
            }
        }
        return ans;
    }
};