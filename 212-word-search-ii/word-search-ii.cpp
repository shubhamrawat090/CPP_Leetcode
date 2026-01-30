class Solution {
    struct TrieNode {
        TrieNode* children[26] = {};
        string word = ""; // store full word at end node
    };

    TrieNode* root = new TrieNode();
    vector<string> ans;
    int rows, cols;

    void insert(const string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            int idx = ch - 'a';
            if (!node->children[idx])
                node->children[idx] = new TrieNode();
            node = node->children[idx];
        }
        node->word = word; // mark complete word
    }

    void dfs(vector<vector<char>>& board, int r, int c, TrieNode* node) {
        char ch = board[r][c];
        int idx = ch - 'a';

        // ❌ no path in Trie → stop immediately
        if (!node->children[idx])
            return;

        node = node->children[idx];

        // ✅ found a word
        if (!node->word.empty()) {
            ans.push_back(node->word);
            node->word.clear(); // avoid duplicates
        }

        // mark visited
        board[r][c] = '#';

        // explore 4 directions
        int dirs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        for (auto& d : dirs) {
            int nr = r + d[0];
            int nc = c + d[1];
            if (nr >= 0 && nc >= 0 && nr < rows && nc < cols &&
                board[nr][nc] != '#') {
                dfs(board, nr, nc, node);
            }
        }

        // backtrack
        board[r][c] = ch;
    }

public:
    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {
        rows = board.size();
        cols = board[0].size();

        // build Trie from words
        for (string& w : words)
            insert(w);

        // DFS from every cell
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                dfs(board, i, j, root);
            }
        }

        return ans;
    }
};
