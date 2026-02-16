class Trie {
    struct Node {
        bool isEnd = false;
        Node* children[26] = {NULL};
    };

    Node* root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* curr = root;
        for(int i=0; i<word.size(); i++) {
            int index = word[i] - 'a';
            if(curr->children[index] == NULL) {
                curr->children[index] = new Node();
            }
            curr = curr->children[index];
        }   
        curr->isEnd = true; // end of word
    }
    
    bool search(string word) {
        Node* curr = root;
        for(int i=0; i<word.size(); i++) {
            int index = word[i] - 'a';
            if(curr->children[index] == NULL) {
                return false; // char not present
            }
            curr = curr->children[index];
        }
        return curr->isEnd;
    }
    
    bool startsWith(string prefix) {
        Node* curr = root;
        for(int i=0; i<prefix.size(); i++) {
            int index = prefix[i] - 'a';
            if(curr->children[index] == NULL) {
                return false; // char not present
            }
            curr = curr->children[index];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */