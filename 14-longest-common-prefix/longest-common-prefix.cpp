class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        int n = strs.size();
        int minSize = INT_MAX;
        for(auto& str: strs) {
            int size = str.size();
            minSize = min(minSize, size);
        }

        int ptr = 0;
        while(ptr < minSize) {
            char curr = strs[0][ptr];
            bool foundAnomaly = false;
            for(int i=1; i<n; i++) {
                if(strs[i][ptr] != curr) {
                    foundAnomaly = true;
                    break;
                }
            }

            if(foundAnomaly) break;
            ans.push_back(curr);
            ptr++;
        }
        return ans;
    }
};