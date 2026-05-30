class Solution {
public:
    vector<int> partitionLabels(string str) {
        int n = str.size();
        unordered_map<char, int> lastIdx;
        for(int i=0; i<n; i++) {
            lastIdx[str[i]] = i;
        }

        int rangeLen = 0;
        int maxIdx = 0;
        vector<int> ans;
        for(int i=0; i<n; i++) {
            rangeLen++;
            maxIdx = max(lastIdx[str[i]], maxIdx);
            if(i == maxIdx) {
                ans.push_back(rangeLen);
                rangeLen = 0;
            }
        }
        return ans;
    }
};