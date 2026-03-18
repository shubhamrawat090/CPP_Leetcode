class Solution {
public:
    string removeDuplicateLetters(string s) {
        string ans;
        vector<int> lastIndex(26, -1);
        vector<bool> taken(26, false);

        int n = s.size();
        for(int i=0; i<n; i++) {
            lastIndex[s[i]-'a'] = i; // store last occurring index of the char
        }

        for(int i=0; i<n; i++) {
            if(taken[s[i] - 'a'] == true) continue;

            while(ans.size() > 0 && s[i] < ans.back() && lastIndex[ans.back() - 'a'] > i) {
                taken[ans.back() - 'a'] = false;
                ans.pop_back();
            }
            ans.push_back(s[i]);
            taken[s[i] - 'a'] = true;
        }

        return ans;
    }
};