class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> keyAnagrams;
        
        int n = strs.size();
        for(int i=0; i<n; i++) {
            string str = strs[i];
            sort(str.begin(), str.end());
            keyAnagrams[str].push_back(strs[i]);
        }

        vector<vector<string>> ans;
        for(auto& entry: keyAnagrams) {
            ans.push_back(entry.second);
        }
        return ans;
    }
};