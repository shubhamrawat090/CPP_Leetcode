class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;

        // APPROACH
        // STEP 1: Create this map anagramGroup: {commonKey: [str1, str2], commonKey2: [str3, str4]}
        // STEP 2: Just return Object.values(anagramGroup)
        
        // STEP 1
        unordered_map<string, vector<string>> anagramGroup;
        for(int i=0; i<strs.size(); i++) {
            string str = strs[i];
            // string key = str;
            // sort(key.begin(), key.end());

            // commonKey optimization: instead of sorting make a frequency string
            // like for "abc", 1#1#1#0#0....till 26 chars
            vector<int> freq(26, 0);
            for(int i=0; i<str.size(); i++) {
                char ch = str[i];
                freq[ch - 'a']++;
            }

            string key = "";
            for(int i=0; i<26; i++) {
                int val = freq[i];
                key += (to_string(val) + '#');
            }
            
            anagramGroup[key].push_back(str);
        }

        // STEP 2
        for(auto &[_, list]: anagramGroup) {
            ans.push_back(list);
        }

        return ans;
    }
};