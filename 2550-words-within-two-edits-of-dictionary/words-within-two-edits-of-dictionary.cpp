class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries,
                                vector<string>& dictionary) {
        // RECURSION IS TOO LARGE SEARCH SPACE - (26(a-z) * 100(n constraint)) ^
        // 2(edits)

        // For each word in dictionary we get the difference - word & wood: diff
        // = 1 If difference <= maxEdits(2) for any word in the dictionary then
        // push ans and stop further execution for that word
        int MAX_EDITS = 2;
        vector<string> ans;
        for (string query : queries) {
            for (string word : dictionary) {
                int diff = 0;
                for(int i=0; i<word.size(); i++) {
                    if(word[i] != query[i]) {
                        diff++;
                    }
                }
                if(diff <= MAX_EDITS) {
                    ans.push_back(query);
                    break;
                }
            }
        }

        return ans;
    }
};