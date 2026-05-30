class Solution {
    struct TrieNode {
        TrieNode* children[26];
        bool isWord;

        TrieNode() {
            for (int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
            isWord = false;
        }
    };

    TrieNode* root;

    void insert(string word) {
        TrieNode* curr = root;

        for (char ch : word) {

            int idx = ch - 'a';

            if (!curr->children[idx]) {
                curr->children[idx] = new TrieNode();
            }

            curr = curr->children[idx];
        }

        curr->isWord = true;
    }

    string getRoot(string word) {

        TrieNode* curr = root;

        string prefix = "";

        for (char ch : word) {

            int idx = ch - 'a';

            if (!curr->children[idx]) {
                return word;
            }

            prefix.push_back(ch);

            curr = curr->children[idx];

            if (curr->isWord) {
                return prefix;
            }
        }

        return word;
    }

public:
    string replaceWords(vector<string>& dictionary,
                        string sentence) {

        root = new TrieNode();

        for (string word : dictionary) {
            insert(word);
        }

        stringstream ss(sentence);

        string word;

        string ans = "";

        while (ss >> word) {
            ans += getRoot(word);
            ans += " ";
        }

        ans.pop_back();

        return ans;
    }
};