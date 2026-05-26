class Solution {
    struct TrieNode {
        TrieNode* children[26];
        bool isWord;
        TrieNode() {
            for (int i = 0; i < 26; i++) {
                children[i] = NULL;
            }
            isWord = false;
        }

        void addWord(string word) {
            TrieNode* curr = this;
            for (int i = 0; i < word.size(); i++) {
                char ch = word[i];
                if (curr->children[ch - 'a'] == NULL) {
                    curr->children[ch - 'a'] = new TrieNode();
                }
                curr = curr->children[ch - 'a'];
            }
            curr->isWord = true;
        }
    };

public:
    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {
        TrieNode* trie = new TrieNode();
        for (string& word : words) {
            trie->addWord(word);
        }

        int rows = board.size(), cols = board[0].size();
        unordered_set<string> ansSet;
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                char ch = board[i][j];
                if (trie->children[ch - 'a'] != NULL) {
                    dfs(board, i, j, trie, visited, ansSet, "");
                }
            }
        }

        vector<string> ans;
        for (string word : ansSet) {
            ans.push_back(word);
        }

        return ans;
    }

    void dfs(vector<vector<char>>& board, int i, int j, TrieNode* trie,
             vector<vector<bool>>& visited, unordered_set<string>& ansSet,
             string str) {
        int rows = board.size(), cols = board[0].size();
        if (i < 0 || j < 0 || i == rows || j == cols)
            return;
        if (visited[i][j])
            return;
        char ch = board[i][j];
        if (trie->children[ch - 'a'] == NULL)
            return;

        str.push_back(ch);
        trie = trie->children[ch - 'a'];

        if (trie->isWord) {
            ansSet.insert(str);
        }

        visited[i][j] = true;

        dfs(board, i + 1, j, trie, visited, ansSet, str);
        dfs(board, i - 1, j, trie, visited, ansSet, str);
        dfs(board, i, j + 1, trie, visited, ansSet, str);
        dfs(board, i, j - 1, trie, visited, ansSet, str);

        visited[i][j] = false;
    }
};