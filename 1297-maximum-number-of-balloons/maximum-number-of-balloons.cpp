class Solution {
public:
    int maxNumberOfBalloons(string text) {
        // b - 2
        // a - 1
        // l - 12
        // l - 12
        // o - 15
        // o - 15
        // n - 14
        int freq[26] = {0};
        for(char ch: text) {
            freq[ch-'a']++;
        }

        freq['l'-'a'] /= 2;
        freq['o'-'a'] /= 2;

        string str = "balloon";
        int minOccur = INT_MAX;
        for(char ch: str) {
            cout<<ch<<": "<<freq[ch-'a']<<endl;
            minOccur = min(minOccur, freq[ch-'a']);
        }

        return minOccur;
    }
};