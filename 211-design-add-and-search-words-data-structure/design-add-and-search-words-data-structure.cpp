class WordDictionary {
    struct Node {
        Node* children[26] = {NULL};
        bool isEnd = false;
    };
    Node* root;
public:
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* curr = root;
        for(int i=0; i<word.size(); i++) {
            int index = word[i] - 'a';
            if(curr->children[index] == NULL) {
                curr->children[index] = new Node();
            }
            curr = curr->children[index];
        }
        curr->isEnd = true;
    }
    
    bool search(string word) {
        return helper(word, 0, root);
    }

    bool helper(string word, int pos, Node* root) {
        if(root == NULL) {
            return false;
        }

        if(pos == word.size()) {
            return root->isEnd == true;
        }

        // . => all 26 char
        if(word[pos] == '.') {
            for(int i=0; i<26; i++) {
                if(helper(word, pos+1, root->children[i])) {
                    return true;
                }
            }
            return false;
        }

        // get index for non dot(.) char
        int index = word[pos] - 'a';
        return helper(word, pos+1, root->children[index]);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */