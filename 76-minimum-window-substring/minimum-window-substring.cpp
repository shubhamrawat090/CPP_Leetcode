class Solution {
public:
    string minWindow(string large, string small) {
        int left = 0, right = 0;
        vector<int> freq(128, 0);
        int minLen = INT_MAX, start = -1;
        int count = 0;
        // pre-insert small's chars
        for(char ch: small) {
            freq[ch]++;
        }

        while(right < large.size()) {
            if(freq[large[right]] > 0) count++;

            freq[large[right]]--;

            while(count == small.size()) {
                // calc min here -> as you need to current starting point(left) when all chars were counted
                int len = right - left + 1;
                if(len < minLen) {
                    minLen = len;
                    start = left;
                }

                freq[large[left]]++;
                if(freq[large[left]] > 0) count--;
                left++;
            }

            right++;
        }

        return start == -1 ? "" : large.substr(start, minLen);
    }
};