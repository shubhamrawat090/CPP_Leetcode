class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;

        // APPROACH
        // STEP 1: Create this map anagramGroup: {commonKey: [str1, str2], commonKey2: [str3, str4]}
        // STEP 2: Just return Object.values(anagramGroup)
        
        // STEP 1
        unordered_map<string, vector<string>> anagramGroup;
        for(string str: strs) {
            string key = str;
            sort(key.begin(), key.end());
            anagramGroup[key].push_back(str);
        }

        // STEP 2
        for(auto keyVal: anagramGroup) {
            ans.push_back(keyVal.second);
        }

        return ans;
    }
};