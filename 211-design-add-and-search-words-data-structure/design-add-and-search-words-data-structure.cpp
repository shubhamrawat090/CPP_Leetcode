class WordDictionary {
    class Node {
    public:
        Node* children[26];
        bool isEnd = false;
        Node() {
            for (int i = 0; i < 26; i++) {
                children[i] = NULL;
            }
        }
    };

    Node* root;

public:
    WordDictionary() { root = new Node(); }

    void addWord(string word) {
        Node* curr = root;
        for (char ch : word) {
            int index = ch - 'a';
            if (!curr->children[index]) {
                curr->children[index] = new Node();
            }
            curr = curr->children[index];
        }
        curr->isEnd = true;
    }

    bool search(string word) { return dfs(word, 0, root); }

    bool dfs(string word, int pos, Node* curr) {
        if (!curr)
            return false;

        if (pos == word.size()) {
            return curr->isEnd; // last char isEnd or not
        }

        char ch = word[pos];
        if (ch == '.') {
            // try all 26 char
            for (int i = 0; i < 26; i++) {
                if (dfs(word, pos + 1, curr->children[i])) {
                    return true;
                }
            }
            return false;
        } else {
            int index = ch - 'a';
            if (!curr->children[index])
                return false;
            return dfs(word, pos + 1, curr->children[index]);
        }
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */