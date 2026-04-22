class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        queue<string> q;
        q.push(beginWord);

        unordered_set<string> wordSet(
            wordList.begin(),
            wordList.end()); // for faster search of words + make sure visited
                             // words don't appear again

        // endWord should be in the list in first place
        if(!wordSet.count(endWord)) return 0; 

        int level = 1;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                string word = q.front();
                q.pop();

                if (word == endWord)
                    return level; // FOUND

                // hot(*ot, h*t, ho*) -> in place of * try a-z and search for
                // possible nbrs in wordSet
                for (int i = 0; i < word.size(); i++) {
                    string nbr = word;
                    for (char ch = 'a'; ch <= 'z'; ch++) {
                        nbr[i] = ch; // replacing *(at pos i) with a-z

                        if (wordSet.count(nbr)) {
                            q.push(nbr);
                            wordSet.erase(nbr); // Like marking nbr as visited
                        }
                    }
                }
            }
            level++;
        }

        return 0; // End word not found
    }
};