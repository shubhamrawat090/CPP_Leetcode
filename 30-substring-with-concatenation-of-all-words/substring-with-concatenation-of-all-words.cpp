class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        // foo : -1
        // bar : -1

        // right <= n-3
        // right += 3 is the jump
        // left += 3 is the jump
        // word => 3 chars[right, right+1, right+2], can use s.substr(right, 3)

        // Treat the same as min window substring question
        // +1 freq of word when right expands
        // -1 freq of word when left shrinks

        // Window size:  ceil((r-l+1)/3)
        // l  r     ==> should be 2, l=0, r=3,
        // abcdef

        // SHRINK When window size = words.size() ==> WINDOW IS SAME AS THE
        // NUMBER OF WORDS Store the left there

        unordered_map<string, int> originalFreq;
        int n = s.size();
        int m = words.size();
        for (string word : words) {
            originalFreq[word]--;
        }

        int jump = words[0].size();
        vector<int> ans;

        // NEW: Run for every possible alignment
        for (int offset = 0; offset < jump; offset++) {

            unordered_map<string, int> freq = originalFreq;

            int count = 0;
            int left = offset;

            for (int right = offset; right <= n - jump; right += jump) {
                string word = s.substr(right, jump);
                if (freq[word] < 0) {
                    count++;
                }
                freq[word]++;

                while (count == m) {
                    int windowSize = ceil((right - left + 1) * 1.0 / jump);
                    if (count == windowSize) {
                        ans.push_back(left);
                    }
                    string leftWord = s.substr(left, jump);
                    if (freq[leftWord] == 0)
                        count--;
                    freq[leftWord]--;
                    left += jump;
                }
            }
        }

        return ans;
    }
};