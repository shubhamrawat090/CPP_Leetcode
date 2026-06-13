class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        vector<char> alphabets;
        for(int i=25; i>=0; i--) {
            char ch = i + 'a';
            alphabets.push_back(ch);
        }

        string ans;
        for(auto& word: words) {
            int sum = 0;
            for(char ch: word) {
                sum += weights[ch - 'a'];
            }
            ans.push_back(alphabets[sum % 26]);
        }
        return ans;
    }
};