class Solution {
public:
    vector<int> partitionLabels(string str) {
        unordered_map<char, int> charIdx;
        int n = str.size();
        for(int i=0; i<n; i++) {
            charIdx[str[i]] = i;
        }

        int itr = 0;
        vector<int> ans;
        while(itr < n) {
            int s = itr;
            int e = charIdx[str[itr]];
            for(int i=s; i <= e; i++) {
                e = max(e, charIdx[str[i]]);
            }
            int range = e - s + 1;
            ans.push_back(range);
            itr = e+1;
        }
        return ans;
    }
};